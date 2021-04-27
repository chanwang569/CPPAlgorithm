#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> lLeftDP(nums.size() );
        int p = 1;
        for(size_t i = 0 ; i < nums.size() ; i++)
        {
            lLeftDP[i] = p;
            p = p * nums[i];
        }

        vector<int> lRightDP(nums.size());
        lRightDP[ nums.size() -1] = 1;
        p = 1;
        for(int j = nums.size() - 1; j>= 0; j--)
        {
            lRightDP[j] = p; 
            p *= nums[j];
        }
        vector<int> lResult;
        for(int i = 0; i < lLeftDP.size(); i++)
        {
            lResult.push_back(lLeftDP[i] * lRightDP[i]);
        }
        return lResult;
    }
};
void case0()
{
    vector<int> lData ={1,2,3,4};
    Solution S1;
    auto result = S1.productExceptSelf(lData);
    assert(std::find(result.begin(), result.end(), 24) != result.end());
}
int main()
{
    case0();
    return 0;
}