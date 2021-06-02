#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0; 
        for(int i = 1 ; i < prices.size();i++)
        {
            if(prices[i] > prices[i -1])
                result += prices[i] - prices[i-1];
        }
        return result;
    }
};
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1 )
            return 0;
        int lMin = prices[0]; 
        int lMax = 0; 
        int lResult = 0; 
        for(int i = 1 ;i < prices.size(); i++)
        {
             if( i == prices.size() -1 )
                {
                    lMax = max(lMax, prices[i]);
                    if(lMax > lMin )
                        lResult += (lMax - lMin);
                }
            else if(prices[i] <= lMin)
            {
                if(lMin < lMax )
                {
                    lResult += (lMax - lMin);
                    lMin = INT_MAX;
                    lMax = 0; 
                }
                lMin = prices[i];
            }
            else 
            {
               
                if(lMax == 0 || prices[i] > lMax )
                {
                    lMax = prices[i];
                }else
                {
                    if(prices[i] < lMax )
                    {
                        lResult += (lMax - lMin);
                        lMin = prices[i];
                        lMax = 0; 
                    }
                }
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
        assert(result == 7);
    }
  
    {
         vector<int> prices = { 1,2,3,4,5};
        auto result = S1.maxProfit(prices);
        assert(result == 4);
    }
    {
         vector<int> prices = {7,6,4,3,1};
        auto result = S1.maxProfit(prices);
        assert(result == 0);
    }   
    {
         vector<int> prices = {1,2};
        auto result = S1.maxProfit(prices);
        assert(result == 1);
    }   
      {
         vector<int> prices = {2,4,1};
        auto result = S1.maxProfit(prices);
        assert(result == 2);
    }  
     {
         vector<int> prices = {3,3,5,0,0,3,1,4};
        auto result = S1.maxProfit(prices);
        assert(result == 8);
    }  
}