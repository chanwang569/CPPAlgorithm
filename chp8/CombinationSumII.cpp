#include<vector>
#include<map>
using namespace std;
//https://leetcode-cn.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            BackTracing(irResult, irCurrent, irCandidate, target, i+1 );
            irCurrent.pop_back();
            target += irCandidate[i];
            while(i+1 < irCandidate.size() && irCandidate[i] == irCandidate[i+1])
                i++;
        }
    }

};

int main()
{
    Solution S1;
    vector<int> lVec{2,5,2,1,2};
    auto lResult = S1.combinationSum2(lVec, 5);

    return 0;
}