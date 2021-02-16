#include<iostream>
#include<cstring>
#include<unordered_map>
#include<vector>
using namespace std;
struct bound
{
    int mLow = 0;
    int mHigh = 0;
    bound(int iLow = 0 , int iHigh = 0): mLow(iLow), mHigh(iHigh){}  
};

int LongestConsecutive(vector<int>& irData)
{
    int lResult = 0;
    unordered_map<int, bound> lHashTable; 
    for(int i = 0; i < irData.size(); i++)
    {
        int lCurrentData = irData[i];
        if(lHashTable.count(lCurrentData) > 0)
        {
            continue;
        }
        auto low = lCurrentData;
        auto high = lCurrentData;
        if(lHashTable.count(lCurrentData -1 ) > 0)
        {
            low = lHashTable[lCurrentData - 1].mLow;
        }
        if(lHashTable.count(lCurrentData + 1) > 0)
        {
            high = lHashTable[lCurrentData + 1].mHigh;
        }
        lHashTable[lCurrentData].mLow  = low; 
        lHashTable[lCurrentData].mHigh = high;

        if(low != lCurrentData)
        {
            lHashTable[low].mHigh = high;
        }
        if(high != lCurrentData)
        {
            lHashTable[high].mLow = low; 
        }
        if(high - low + 1 > lResult)
            lResult = high - low + 1;
    }

   return lResult;
}
void  case0_Acceptance()
{
    vector<int> lData{31, 6 , 32, 1, 3, 2};
    auto lResult = LongestConsecutive(lData);
}
int main()
{
    case0_Acceptance();
    return 0;
}