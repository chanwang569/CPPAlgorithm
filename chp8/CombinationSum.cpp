#include<vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(int k, int n) {
        vector<vector<int>> lResult; 
        vector<int> lCurrent;
        dfs(lResult, lCurrent, k, n, 1);
       
       return lResult;
    }
private:
    void dfs(vector<vector<int>>& irResult, vector<int>& irCurrent, int k, int n, int left )
    {
        if(irCurrent.size() == k )
        {
            irResult.push_back(irCurrent);
            return;
        }
        if(irCurrent.size() > k )
            return; 
        for(int i = left ; i < n; i++)
        {
            irCurrent.push_back(i);
            dfs(irResult, irCurrent, k, n, i + 1);
            irCurrent.pop_back();
        }
    }
};
int main()
{
    Solution S1;
    vector<vector<int>> lResult = S1.combinationSum(3,7);
    return 0;
}