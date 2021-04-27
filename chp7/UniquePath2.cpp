#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        if (obstacleGrid[0][0] == 1)
        {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = (dp[i - 1][0] == 1 && obstacleGrid[i][0] == 0 )? 1 : 0;
        }
        for (int j = 1; j < n; j++)
        {
            dp[0][j] = (dp[0][j-1] == 1 && obstacleGrid[0][j] == 0 )? 1 : 0;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    {
        vector<vector<int> > lVec;
        lVec.push_back({0, 0, 0});
        lVec.push_back({0, 1, 0});
        lVec.push_back({0, 0, 0});
        Solution S1;
        auto result = S1.uniquePathsWithObstacles(lVec);
        assert(result == 2);
    }
    {
        vector<vector<int> > lVec;
        lVec.push_back({0, 1, 0, 0});
        lVec.push_back({1, 0, 0, 0});
        lVec.push_back({0, 0, 0, 0});
        lVec.push_back({0, 0, 0, 0});
        Solution S1;
        auto result = S1.uniquePathsWithObstacles(lVec);
        assert(result == 0);
    }

    return 0;
}