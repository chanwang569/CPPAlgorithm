#include<string> 
#include<vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty() || word2.empty())
            return max(word1.length(), word2.length());
        vector< vector<int> > lDP(word1.length()+1, vector<int>(word2.length() + 1, 0)); 
        for(size_t i = 0 ; i < lDP.size(); i++)
            lDP[i][0] = i; 
        for(size_t j = 0 ; j < lDP[0].size(); j++)
            lDP[0][j] = j;
        
        for(size_t i = 1; i <= word1.length(); i++)
        {
            for(size_t j = 1; j<=word2.length(); j++)
            {
                if(word1[i-1] == word2[j-1]) 
                {
                    lDP[i][j] = lDP[i-1][j-1];
                }else
                {
                    lDP[i][j] = 1 + min(lDP[i-1][j-1],min(lDP[i-1][j], lDP[i][j-1]));
                }    
            }
        }
        return lDP[word1.length()][word2.length()];
    }
};
void Test()
{
    Solution S1;
    int result = S1.minDistance("intention", "execution");

    assert(result  == 5);
}
int main()
{
    Test();
    return 0;
}