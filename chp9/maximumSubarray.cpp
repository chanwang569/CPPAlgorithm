#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int lMax = INT_MIN;
        int sum = 0; 
        for(int i = 0; i < nums.size(); i++)
        {
            sum +=nums[i];
            lMax = max(lMax, sum);
            if(sum < 0)
                sum = 0;
        }
        return lMax;
    }
};
int main()
{
    vector<int> nums ={-2,1,-3,4,-1,2,1,-5,4};
    Solution S1;
    assert( S1.maxSubArray(nums) ==6);
}