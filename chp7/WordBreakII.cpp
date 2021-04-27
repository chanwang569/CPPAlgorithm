#include<cstring>
#include<vector>
#include<iostream>
#include<unordered_map>
//#include<cstdlib>

using namespace std;
class Solution {
public:
     vector<string> wordBreak(string s, vector<string>& wordDict) {
         unordered_map<string, vector<string> > lcache;
         return hWordBreak(s, wordDict, lcache);
    }
private:
    vector<string> hWordBreak(string s, vector<string>& wordDict, unordered_map<string, vector<string> > &cache)
    {
        if(cache.find(s) != cache.end())
        {
            return cache[s];
        }
        vector<string> vs; 
        if(s.empty())
        {
            vs.push_back(string());
            return vs; 
        }

        for(size_t len = 1; len <= s.length(); len++)
        {
            string prefix = s.substr(0, len);
            if(find(wordDict.begin(), wordDict.end(), prefix) != wordDict.end())
            {
                string suffix = s.substr(len);
                auto result = hWordBreak(suffix, wordDict, cache);
                for(size_t i = 0; i < result.size(); i++)
                {
                    if(result[i].empty() )
                    {
                        vs.push_back(prefix);
                    }    
                    else
                    {
                        vs.push_back(prefix + " " + result[i]);
                    }
                }
            }
        }
        cache[s] = vs;
        return vs; 
    }
};
void Acceptance()
{
    vector<string> lDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    string lStr  = "pineapplepenapple";
    Solution S1;
    vector<string> lResult = S1.wordBreak(lStr,lDict);
    assert(lResult.size() == 3);
}

void Acceptance2()
{
    vector<string> lDict; 
    lDict.push_back("apple");
    lDict.push_back("pen");
    string lStr  = "applepenapple";
    Solution S1;
    S1.wordBreak(lStr,lDict);
}

void Acceptance3()
{
    vector<string> lDict; 
    lDict.push_back("cats");
    lDict.push_back("dog");
    lDict.push_back("sand");
    lDict.push_back("and");
    string lStr  = "catsandog";
    Solution S1;
   S1.wordBreak(lStr,lDict) ;
}
int main()
{
  Acceptance();
//   Acceptance2();
//   Acceptance3();
}