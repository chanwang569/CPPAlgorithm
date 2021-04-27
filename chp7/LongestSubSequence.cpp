#include <vector>
using namespace std;
class Solution
{
public:
    int LSS(vector<int> &coins, int amount)
    {
        vector<int> lDP(amount+1, INT_MAX);
        lDP[0] = 0;
        
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                int lLeft = i - coins[j];
                if( lLeft >= 0 && lDP[lLeft ] < lDP[i] )
                {
                    lDP[i] = lDP[lLeft] + 1;
                }
            }
          
        }
        return lDP[amount] == INT_MAX ? 0 : lDP[amount];
    }
};
int main()
{
    Solution S1;
    vector<int> lCoins = {2};
    auto result = S1.LSS(lCoins,3);
    assert(result == 0);
    lCoins.clear();
    lCoins = {1, 2 ,5};
    result = S1.LSS(lCoins,11);
    assert(result == 3);
    return 0;
}