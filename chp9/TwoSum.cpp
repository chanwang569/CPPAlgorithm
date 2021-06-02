#include<unordered_map>
#include<vector>
using namespace std;
// https://leetcode-cn.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> lHashMap;
        vector<int> lResult; 
        for(size_t i = 0 ; i < nums.size(); i++)
        {
            if(lHashMap.find(nums[i]) != lHashMap.end())
            {
                lResult.push_back(lHashMap[nums[i]]);
                lResult.push_back(i);
                break;
            }else
            {
                lHashMap[target - nums[i]] = i ; 
            }
        }
        return lResult;
    }
};

int main()
{
    Solution S1;
    vector<int> lData ={2,7,11,15};
    auto result = S1.twoSum(lData, 9);
    return 0;
}