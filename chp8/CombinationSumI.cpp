#include<vector>
#include<map>
using namespace std;
//https://leetcode-cn.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> lResult; 
        vector<int> lCurrent; 
       
        BackTracing(lResult, lCurrent, candidates, target, 0);
        return lResult;
    }
private: 
    void BackTracing(vector<vector<int>> &irResult, vector<int> & irCurrent, vector<int> & irCandidate, int target, int optionStart)
    {
        if(target == 0)
        {
            irResult.push_back(irCurrent);
            return; 
        }
        if(target < 0)
            return; 

        for(int i = optionStart; i < irCandidate.size(); i++)
        {
            irCurrent.push_back(irCandidate[i]);
            target -= irCandidate[i];
            BackTracing(irResult, irCurrent, irCandidate, target, i );
            irCurrent.pop_back();
            target += irCandidate[i];
        }
    }

};

int main()
{
    Solution S1;
    vector<int> lVec{2,3,6,7};
    auto lResult = S1.combinationSum(lVec, 7);

    return 0;
}