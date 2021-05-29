#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> lResult; 
        vector<string> lCurrent; 
        dfs(s, 0 , lCurrent, lResult);
        return lResult;

    }
private:
    void dfs(string s, size_t iStart, vector<string>& lCurrent, vector<vector<string>> &irResult)
    {
        if( iStart >= s.size())
        {
            irResult.push_back(lCurrent);
            return ;
        }else
        {
            for(size_t i = iStart; i < s.size(); i++)
            {
                if(isValid(s, iStart, i ))
                {
                    lCurrent.push_back (s.substr(iStart, i- iStart + 1));
                    dfs(s, i+1, lCurrent, irResult);
                    lCurrent.pop_back();
                }
            }       
        }
    }
    bool isValid(string s, int iStart , int iEnd )
    {
        if(iStart < 0 || iEnd >= s.length())
            return false; 
        while(iStart <= iEnd)
        {
            if(s[iStart] != s[iEnd])
            {
                 return false; 
            }   
            iStart++; 
            iEnd--;
        }
        return true; 
    }
};
int main()
{
    string s{"aab"};
    Solution S1;
    vector<vector<string>> lResult = S1.partition(s);
    assert(lResult.size() == 2);
    return 0;
}