#include <vector>
using namespace std;
class Solution
{
public:
    int LSS(vector<int> &coins, int amount)
    {
        vector<int> lDP(amount + 1, 0);
        lDP[0] = 1;
        for(int i = 0; i < coins.size(); i++)
        {
            for(int j = 1 ; j <=amount; j++)
            {
                if( j - coins[i] >= 0)
                    lDP[j] += lDP[j - coins[i]];
            }
        }
      
        return lDP[amount];
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
    result = S1.LSS(lCoins,5);
    assert(result == 4);
    return 0;
}