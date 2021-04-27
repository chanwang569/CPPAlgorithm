#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lDP(nums.size(), 1);
        for(int i = 0 ; i < nums.size();i++)
        {
            for(int j = 0 ; j < i; j++)
            {
                if(nums[i] > nums[j] && lDP[j] + 1 > lDP[i] )
                {
                    lDP[i] = lDP[j] + 1;
                }
            }
        }

        int lResult = 0; 
        for(int i = 0; i < lDP.size();i++)
        {
            if(lResult < lDP[i])
                lResult = lDP[i];
        }  

        return lResult; 
    }
};

void case2()
{
    vector<int> lvec = {0,1,0,3,2,3};
    Solution S1;
    auto lResult = S1.lengthOfLIS(lvec);
    assert(lResult == 4);

}

void case1()
{
    vector<int> lvec = {10,9,2,5,3,7,101,18};
    Solution S1;
    auto lResult = S1.lengthOfLIS(lvec);
    assert(lResult == 4);

}
void case0()
{
    vector<int> lvec = {7,7,7,7,7,7,7};
    Solution S1;
    auto lResult = S1.lengthOfLIS(lvec);
    assert(lResult == 1);

}
int main()
{
    case0();
    return 0;
}