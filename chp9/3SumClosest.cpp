#include<vector> 
#include<algorithm>
#include<numeric>
using namespace std;

// https://leetcode-cn.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        if(nums.size()<= 3) accumulate(nums.begin(), nums.end(),0);
        sort(nums.begin(),nums.end());
        int lSize = nums.size();
        int total = nums[0] + nums[1] + nums[2];

        for(int i = 0 ; i < lSize ; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int low = i + 1; 
            int high = lSize -1; 
            while(low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                if ( sum == target)
                {
                    return target;
                }
                else if(abs(target - sum) < abs(target - total) )
                {
                    total = sum ; 
                }
               
                if ( sum < target)
                {
                   low++;
                }else
                {
                    high--;
                }
            }
        }
        return total;
    }
};
int main()
{
    Solution S1; 
   {
        vector<int> nums = {-1,2,1,-4};
        int lResult = S1.threeSumClosest(nums, 1);
        assert(lResult == 2);
       
    
   }
   {
       vector<int> nums = {0,2,1,-3};
       int lResult = S1.threeSumClosest(nums, 1);
        assert(lResult == 0);
   }
    return 0;
 
}