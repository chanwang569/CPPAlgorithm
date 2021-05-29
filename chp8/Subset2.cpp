#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// https://leetcode-cn.com/problems/subsets-ii/
class Solution1 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> lResult; 
        lResult.push_back(vector<int>());
        map<int,int> lNumCountMap;
        for(auto& it: nums)
        {
            if(lNumCountMap.find(it) == lNumCountMap.end())
            {
                lNumCountMap[it] = 1;
            }else
            {
                lNumCountMap[it]++;
            }
        }

        for(auto& it : lNumCountMap)
        {
            int lFirstTimeCount = lResult.size();
            for(size_t i = 0 ; i < lFirstTimeCount; i++)
            {
                vector<int> lTmp = lResult[i];
                lTmp.push_back(it.first);
                lResult.push_back(lTmp);
            }
            if(it.second > 1 )
            {
                for(int j = 1 ; j < it.second; j++)
                {
                    int lSecondTimeCount = lResult.size();
                    for(int i = lFirstTimeCount; i < lSecondTimeCount; i++)
                    {
                        vector<int> lTmp = lResult[i];
                        lTmp.push_back(it.first);
                        lResult.push_back(lTmp);
                    }
                    lFirstTimeCount = lSecondTimeCount;
                }
            }
        }
        return lResult;

    }
};
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<int> lExistingResult;
        sort(nums.begin(), nums.end());
        vector<vector<int> > lResult;
        dfs(nums, 0, lExistingResult,lResult );
        return lResult;
    }
private:
    void dfs(vector<int>& nums, int iStart, vector<int>& irExisting, vector<vector<int> > & orResult)
    {
        orResult.push_back(irExisting);
        for(size_t i = iStart; i < nums.size(); i++)
        {
            if(i > iStart && nums[i] == nums[i-1])
                continue;// only process the first duplciate member. 
            irExisting.push_back(nums[i]);
            dfs(nums, i + 1, irExisting, orResult);
            irExisting.pop_back();
        }
    }

};


int main()
{
    {
        vector<int> nums{2, 2, 1};
        Solution S1;
        auto result = S1.subsetsWithDup(nums);
        assert(result.size() == 6);

        nums.clear();
        nums.push_back(0);
        auto result2 = S1.subsetsWithDup(nums);
        
    }
    
    {
        vector<int> nums{2, 2, 1,1};
        Solution S1;
        auto result = S1.subsetsWithDup(nums);
        assert(result.size() == 9);
    }
    return 0;
}
