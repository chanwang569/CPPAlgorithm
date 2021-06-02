#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 1) 
            return 0;
        int dp0 = 0;          // buy and sell 0 times to the end. 
        int dp1 = -prices[0]; // buy 1 and sell 0 times to the end. 
        int dp2 = INT_MIN;    // buy 1 and sell 1 times to the end.  
        int dp3 = INT_MIN;    // buy 2 and sell 1 times to the end. 
        int dp4 = INT_MIN;    // buy 2 and sell 1 times to the end. 
        for(int i = 1 ; i < prices.size(); i++)
        {
            dp1 = max(dp0 - prices[i], dp1);
            dp2 = max(dp1 + prices[i], dp2);
            dp3 = max(dp2 - prices[i], dp3);
            dp4 = max(dp3 + prices[i], dp4);
        }
        return dp4;
    }
};
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if(prices.size() <= 1 )
//             return 0;
//         int lMin = prices[0]; 
//         int lMax = 0; 
//         vector<int> lResult; 
//         for(int i = 1 ;i < prices.size(); i++)
//         {
//              if( i == prices.size() -1 )
//                 {
//                     lMax = max(lMax, prices[i]);
//                     if(lMax > lMin )
//                         lResult.push_back(lMax - lMin);
//                 }
//             else if(prices[i] <= lMin)
//             {
//                 if(lMin < lMax )
//                 {
//                     lResult.push_back(lMax - lMin);
//                     lMin = INT_MAX;
//                     lMax = 0; 
//                 }
//                 lMin = prices[i];
//             }
//             else 
//             {
               
//                 if(lMax == 0 || prices[i] > lMax )
//                 {
//                     lMax = prices[i];
//                 }else
//                 {
//                     if(prices[i] < lMax )
//                     {
//                         lResult.push_back(lMax - lMin);
//                         lMin = prices[i];
//                         lMax = 0; 
//                     }
//                 }
//             }
        
//         }
//         if(lResult.size() ==1)
//         {
//             return lResult[0]; 
//         }
//         else if(lResult.size() >=2)
//         {
//             sort(lResult.begin(), lResult.end(),std::greater<int>());
//             return lResult[0] + lResult[1];
//         }
//         return 0;    

//     }
// };
int main()
{
    Solution S1; 
    // {
    //     vector<int> prices = {7,1,5,3,6,4};
    //     auto result = S1.maxProfit(prices);
    //     assert(result == 7);
    // }
  
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
         vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
        auto result = S1.maxProfit(prices);
        assert(result == 13);
    }   
    //   {
    //      vector<int> prices = {2,4,1};
    //     auto result = S1.maxProfit(prices);
    //     assert(result == 2);
    // }  
     {
         vector<int> prices = {3,3,5,0,0,3,1,4};
        auto result = S1.maxProfit(prices);
        assert(result == 6);
    }  
}