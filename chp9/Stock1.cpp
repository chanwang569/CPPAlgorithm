#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1 )
            return 0;
        int lMin = prices[0]; 
        int lMax = 0; 
        int lResult = 0; 
        for(int i = 1 ;i < prices.size(); i++)
        {
            if(prices[i] > lMin)
            {
                
                 lResult = max( lResult, prices[i] - lMin); 
            }else
            {
                lMin = prices[i];
            }
               
            
        }
        return lResult; 

    }
};
int main()
{
    Solution S1; 
    {
        vector<int> prices = {7,1,5,3,6,4};
        auto result = S1.maxProfit(prices);
        assert(result == 5);
    }
  
    {
         vector<int> prices = { 7,6,4,3,1};
        auto result = S1.maxProfit(prices);
        assert(result == 0);
    }
   
}