#include<cstring>
#include<vector>
#include<iostream>
//#include<cstdlib>

using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool lbCharBreaks[s.length() +1] ;
        for(auto i = 0 ; i < s.length() + 1; i++)
        {
            lbCharBreaks[i] = false; 
        }  
        lbCharBreaks[0] = true;

        for(size_t i = 1; i < s.length()+1; i++)
        {
            lbCharBreaks[i] = false; 
            for(size_t j = 0; j <= i ; j++)
            {
                if( lbCharBreaks[j]) 
                {
                    string substr =  s.substr(j, (i - j));
                    if(std::find(wordDict.begin(), wordDict.end(),substr) != wordDict.end())
                    {
                        lbCharBreaks[i] = true;
                    }
                }
            }

        }

        return lbCharBreaks[s.length()]; 
    }
};
void Acceptance()
{
    vector<string> lDict; 
    lDict.push_back("leet");
    lDict.push_back("code");
    string lStr  = "leetcode";
    Solution S1;
    assert(S1.wordBreak(lStr,lDict) ==true);
}

void Acceptance2()
{
    vector<string> lDict; 
    lDict.push_back("apple");
    lDict.push_back("pen");
    string lStr  = "applepenapple";
    Solution S1;
    assert(S1.wordBreak(lStr,lDict) ==true);
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
    assert(S1.wordBreak(lStr,lDict) ==false);
}
int main()
{
  Acceptance();
  Acceptance2();
  Acceptance3();
}