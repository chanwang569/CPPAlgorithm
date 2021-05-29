#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string lPath; 
        vector<string> lResult;
        hGenerateParenthesis(n, n, lPath, lResult);
        return lResult;
    }
private: 
    void hGenerateParenthesis(int lLeft, int rLeft, string& iorPath, vector<string>& iorResult)
    {
        if(lLeft < 0 && rLeft < 0 )
            return;
        if(lLeft > 0)
        {
            iorPath.append("(");
            hGenerateParenthesis(lLeft-1, rLeft,iorPath, iorResult);
            iorPath.pop_back();
        }
        if(lLeft < rLeft)
        {
            iorPath.append(")");
            rLeft -= 1; 
            if(rLeft == 0 )
                iorResult.push_back(iorPath);
            hGenerateParenthesis(lLeft, rLeft, iorPath, iorResult);
            iorPath.pop_back();
        }
    }
};
int main()
{
    Solution S1;
    
    assert(S1.generateParenthesis(2).size() == 2);
    assert(S1.generateParenthesis(5).size() == 5);
    assert(S1.generateParenthesis(1).size() == 1);

    
    return 0;
}