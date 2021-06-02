#include<vector> 
#include<algorithm>
using namespace std;

// https://leetcode-cn.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> lResults; 
        int lSize = nums.size();
        for(int i = 0 ; i < lSize ; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int low = i + 1; 
            int high = lSize -1; 
            while(low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                if(sum == 0 )
                {
                    vector<int> lTmp = {nums[i], nums[low], nums[high]};
                    lResults.push_back(lTmp);
                     do{
                        low++;
                    }while(low < high && nums[low] == nums[low -1]);
                    do{
                        high--;
                    }while(low < high && nums[high] == nums[high+1]);
                }else if( sum < 0 )
                {
                  
                    low++;
                   
                }else
                {
                   
                    high--;
                    
                   
                }
            }
        }
        return lResults;
    }
};
int main()
{
    {
        vector<int> nums = {-2, 0 , 0 ,2 ,2 };
        Solution S1;
        auto lResult = S1.threeSum(nums);
        assert(lResult.size() == 1);
    }
     {
        vector<int> nums = {0,0,0};
        Solution S1;
        auto lResult = S1.threeSum(nums);
       assert(lResult.size() == 1);
    }
     return 0;
 
}