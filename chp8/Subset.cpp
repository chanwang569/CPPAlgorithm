#include <vector>
#include <algorithm>
using namespace std;
//  "-fsanitize=address",
class Solution
{
public:
  vector<vector<int>> subsets(vector<int>& nums) {
       vector<int> lExistingResult;
        sort(nums.begin(), nums.end());
        vector<vector<int> > lResult;
        dfs(nums, 0, lExistingResult,lResult );
        return lResult;
  }
private:
    void dfs(vector<int>& nums, int iStart, vector<int>& irExisting, vector<vector<int> > & orResult)
    {
        orResult.push_back(irExisting); // Add {} and subsets
        for(size_t i = iStart; i < nums.size(); i++)
        {
            irExisting.push_back(nums[i]); // considering the ith number is in the result. 
            dfs(nums, i + 1, irExisting, orResult);
            irExisting.pop_back(); // considering the ith number is not in the result. 
        }
    }
};
class Solution4
{
public:
  vector<vector<int>> subsets(vector<int>& nums) {
       int lTotalCount = pow(2, nums.size());
        vector<vector<int>> lResult; 
        for(int i = 0 ; i <= lTotalCount; i++)
        {
            vector<int> lTmp; 
            for(int j = 0 ; j < nums.size(); j ++)
            {
                int tmp = 1 << j; 
                bool lNeedAdd  = i & tmp; 
                if(i & (1 << j) )
                {
                    lTmp.push_back(nums[j]);
                }
            }
             lResult.push_back(lTmp);
        }

        return lResult;
  }
};
class Solution3 
{
public:
  vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> lResult; 
        vector<int> lCurrentAnswer;

        for(int i = 0; i <= nums.size(); i++)
        {
            dfs(0, i, nums, lCurrentAnswer,lResult);
            lCurrentAnswer.clear();
        }
        return lResult;
    }
private: 
    void dfs( int iStart, int iSize, vector<int>& nums, vector<int>& irCurrent, vector<vector<int>>& irResult)
    {
        if(iSize == 0 )
        {
            irResult.push_back(irCurrent);
             return;
        }
        for(int i = iStart; i < nums.size(); i++)
        {
            irCurrent.push_back(nums[i]);
            dfs(i+1, iSize - 1, nums, irCurrent, irResult);
            irCurrent.pop_back();
        }
    }
};


class Solution2
{
public:
    vector<vector<int> > subsets(vector<int> &nums){
        vector<vector<int>> lResult;
        lResult.push_back(vector<int>());
        for(size_t i = 0 ; i < nums.size(); i++)
        {
            size_t lCurrentCount  = lResult.size();
            for(size_t j = 0 ; j < lCurrentCount; j++)
            {
                vector<int> lTmp = lResult[j];
                lTmp.push_back(nums[i]);
                lResult.push_back(lTmp);
            }
        }
        return lResult;
    }
};

class Solution1
{
public:
    vector<vector<int> > subsets(vector<int> &nums)
    {
        vector<int> lExistingResule;
        sort(nums.begin(), nums.end());
        vector<vector<int> > lResult;
        lResult.push_back(lExistingResule); // empty set. 
        dfs(nums, 0, lExistingResule, lResult);
        return lResult;
    }
private: 
    void dfs(vector<int> &nums, int pos, vector<int> &irExisting, vector<vector<int> > &orResult)
    {
        if(pos >= nums.size())
            return; 
        irExisting.push_back(nums[pos]);
        orResult.push_back(irExisting); // current node is added
        
        dfs(nums, pos+ 1, irExisting, orResult); // process sub nodes
        irExisting.pop_back();

        // current node is not added. 
        dfs(nums, pos+1, irExisting, orResult); // process sub nodes 
    }
};

int main()
{
    vector<int> nums{1, 2, 3};
    Solution S1;
    auto result = S1.subsets(nums);
    assert(result.size() == 8);
}