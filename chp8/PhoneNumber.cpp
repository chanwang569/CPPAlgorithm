#include<vector>
#include<string>
using namespace std;
//https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
// Time Complex O(n3)
class Solution {
public:
    vector<string> letterCombinations(string digits) {
       
        vector<string> lDic; 
        lDic.push_back(""); // 0 
        lDic.push_back(""); // 1
        lDic.push_back("abc");//2
        lDic.push_back("def"); 
        lDic.push_back("ghi");
        lDic.push_back("jkl");
        lDic.push_back("mno");
        lDic.push_back("pqrs");
        lDic.push_back("tuv");
        lDic.push_back("wxyz");
        vector<string> lResult; 
         if(digits.empty() || digits =="" ) return lResult; 
        string lCurrent; 
        BackTracing(lResult, lCurrent, digits, lDic, 0);
        return lResult;
    }

private:
    void BackTracing(vector<string>& irResult, string& irCurrent, string digits, vector<string>& irDic, int iPos)
    {
        if(iPos == digits.size())
       {
           if(digits.size()  == irCurrent.size())
                irResult.push_back(irCurrent);
           return; 
       }
       int index = digits[iPos] - '0';
       for(size_t i = 0; i < irDic[index].size(); i++)
       {
           irCurrent.push_back(irDic[index][i]);
           BackTracing(irResult, irCurrent, digits, irDic, iPos + 1);
           irCurrent.pop_back();
       }  
    }
};
int main()
{
    string digits = "23";
    Solution S1;
    vector<string> lResult = S1.letterCombinations(digits);
    assert(lResult.size() == 9);

    digits.clear();
    digits = "";
    lResult = S1.letterCombinations(digits);
    assert(lResult.size() == 9);
    return 0; 
}