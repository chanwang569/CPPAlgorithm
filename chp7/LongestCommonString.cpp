#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int> > lDP(text1.length() + 1, vector<int>(text2.length() + 1, 0));

        for(size_t i = 0 ; i <= text1.length(); i++ )
        {
            for(size_t j = 0; j <= text2.length(); j++)
            {
                if(i == 0 || j == 0)
                {
                    lDP[i][j] = 0;
                }
                else if(text1[i - 1] == text2[j - 1])
                {
                    lDP[i][j ] = lDP[i - 1][j - 1] + 1;
                }
                else
                {
                    lDP[i][j] = lDP[i-1][j] > lDP[i][j - 1 ]? lDP[i-1][j]: lDP[i][j-1];
                }
            }
        }
        return lDP[text1.length()][text2.length()];
            
    }
};

void case_0()
{
    string s1("abcde");
    string s2("ace");
    Solution S1;
    auto result = S1.longestCommonSubsequence(s1, s2);
    assert(result ==3);
}
int main()
{
    case_0();
    return 0;
}