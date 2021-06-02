#include<vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0; 
        if(nums.size() == 1) return nums[0];
        int lMax = nums[0], lMin = nums[0]; 
        int lResult = nums[0]; 
        for(int i = 1; i < nums.size(); i++)
        {
            int tmp = lMax;
            lMax = max(lMax* nums[i], max(nums[i], lMin*nums[i]));
            lMin = min(tmp* nums[i], min(nums[i], lMin*nums[i]));
            lResult = max(lResult, lMax);
        }
        return lResult;
    }
};

int main()
{
    Solution S1;
    {
        vector<int> nums ={2,3,-2,4};
        assert(S1.maxProduct(nums) ==6);
    }
  {
        vector<int> nums ={-4,-3,-2};
        assert(S1.maxProduct(nums) ==12);
  }

}