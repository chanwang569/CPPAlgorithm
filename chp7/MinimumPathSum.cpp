#include<vector>
#include<iostream>
using namespace std;
class Solution{
public:
   int minPathSum(vector<vector<int>>& grid) {
         if (grid.empty() || grid[0].empty())
            return 0;
     
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
        {
            dp[i][0] += dp[i-1][0];
        }
        for (int j = 1; j < n; j++)
        {
            dp[0][j] += dp[0][j-1];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
              dp[i][j] = min(dp[i-1][j], dp[i][j -1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
   }
};

int main()
{
    vector< vector<int> > lDataVec;
    lDataVec.push_back({1,3,1});
    lDataVec.push_back({1,5,1});
    lDataVec.push_back({4,2,1});
    Solution S1;
    
    return 0; 
}