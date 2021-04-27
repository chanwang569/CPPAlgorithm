#include<vector>
#include<iostream>
using namespace std;
class Solution{
public:
    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1) return 0;
       vector< vector<int> > lDP(m, vector<int>(n, 1));
       for(int i = 1 ; i < m ; i++)
        for(int j = 1 ; j < n; j++)
        {
            lDP[i][j] = lDP[i-1][j] + lDP[i][j-1];
        }
        return lDP[m-1][n-1];
    }
};

int main()
{
    Solution S1;
    auto result = S1.uniquePaths(3, 2);
    return 0; 
}