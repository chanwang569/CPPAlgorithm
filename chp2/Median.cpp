#include <vector>
using namespace std;
int hGetMdedianByQuickSelect(vector<int> &irData, int low, int high, int iSize)
{
    int lPivot = low;
    int lPivotValue = irData[lPivot];
    for(int i = low + 1; i <= high; i++)
    {
        if(irData[i] < irData[low])
        { 
            lPivot++;
            int tmp = irData[lPivot];
            irData[lPivot] = irData[i];
            irData[i] = tmp;
        }
    }
    int tmp = irData[low];
    irData[low] = irData[lPivot];
    irData[lPivot] = tmp;
    // why lPivot - low + 1 ?  Suppose [1,2 ,3 ] lPivot = 1, iSize  = 2 , how to get it?  
    if(lPivot - low + 1 == iSize)
    {
        return irData[lPivot];
    }
    else if(lPivot - low + 1 > iSize) 
    {
        // still [ 1 , 2, 3 ], lPivot = 2; 
        return hGetMdedianByQuickSelect(irData,low, lPivot-1, iSize);
    }else
    {
        // Still [1, 2, 3] lPivot = 0 ; 
        return hGetMdedianByQuickSelect(irData,lPivot +1, high, iSize - (lPivot - low + 1));
    }
}
int getMedian(vector<int> &irData)
{
    if(irData.size() == 0)
    {
        return 0;
    }
    // why irData.size() + 1? consider the case size==0 and we want to return the 1st element.
    return hGetMdedianByQuickSelect(irData, 0, irData.size()-1, (irData.size() + 1)/2);  
}

void case_acceptance()
{
    vector<int> lVec = {4, 5, 1, 2, 3};
    auto lResult = getMedian(lVec);
    assert(lResult == 3);
    vector<int> lVec2 = {7, 9, 4, 5};
    auto lResult2 = getMedian(lVec2);
    assert(lResult2 == 5);
}
int main()
{
    case_acceptance();
    return 0;
}