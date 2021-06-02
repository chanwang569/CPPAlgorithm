#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<vector<int>> SubarraySum(vector<int>& nums)
    {
        map<int,int> lhash;
        lhash[0] = 0;
        int sum = 0; 
        vector<vector<int>>lResult; 
        for(int i = 0 ; i < nums.size();i++)
        {
            sum += nums[i];
            if(lhash.find(sum) !=lhash.end())
            {
                vector<int> lTmp; 
                lTmp.push_back(lhash[sum]);
                lTmp.push_back(i);
                lResult.push_back(lTmp);
            }
            else
            {
                lhash[sum] = i+1;
            }
        }
        return lResult;
    }
};

int main()
{
    Solution S1;
    vector<int> nums ={-3, 1, 2, -3, 4};
    auto result  = S1.SubarraySum(nums);
    assert(result.size() ==2);
}