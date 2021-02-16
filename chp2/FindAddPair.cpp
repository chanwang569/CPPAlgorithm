#include<iostream>
#include<cstring>
#include<unordered_map>
#include<vector>
using namespace std;
vector<size_t> FindPairSumAsNumber(vector<int>& irData, int iValue)
{
    unordered_map<int, int> lHashMap;
    vector<size_t> lResult(2); 
    for(auto it = irData.begin(); it != irData.end();it++)
    {
        size_t lPos = it - irData.begin();
        int lPair = iValue - *it ;
        if(lHashMap.count(lPair) > 0 )
        {
            lResult.push_back(lPos);
            lResult.push_back(lHashMap[lPair]);
            break;
        }else
        {
            lHashMap[*it] = lPos;
        }
    }
    return lResult;
}

void case0_accept()
{
    vector<int> lVec{1,2};
    auto lResult = FindPairSumAsNumber(lVec, 3);
}

int main()
{
    case0_accept();
    return 0;
}