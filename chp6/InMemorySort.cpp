#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <array>
#include <queue>
#include <iostream>

using namespace std;

class Solution
{
public:
    // Why iTmp is used?
    // 1. For the case large memory required.
    // 2. To avoid frequent stack memory allocation.
    // Whether iTmp will be double write? No.
    void MergeSort(vector<int> &irData, vector<int> &iTmp, size_t iStart, size_t iEnd)
    {
        if (iStart >= iEnd)
            return;
        size_t lMiddle = (iEnd + iStart) / 2;
        MergeSort(irData, iTmp, iStart, lMiddle);
        MergeSort(irData, iTmp, lMiddle + 1, iEnd);
        for (size_t i = iStart; i <= lMiddle; i++)
        {
            iTmp.push_back(irData[i]);
        }
        size_t lLow = 0, lHigh = lMiddle + 1, lCurrentPos = iStart;
        while (lLow < iTmp.size() && lHigh <= iEnd)
        {
            if (iTmp[lLow] < irData[lHigh])
            {
                irData[lCurrentPos++] = iTmp[lLow++];
            }
            else
            {
                irData[lCurrentPos++] = irData[lHigh++];
            }
        }
        while (lLow < iTmp.size())
        {
            irData[lCurrentPos++] = iTmp[lLow++];
        }
        iTmp.clear();
    }
    void QuickSort(vector<int> &irData, size_t iStart, size_t iEnd)
    {
        if (iStart >= iEnd || iEnd > irData.size() || iStart > irData.size())
            return;
        size_t lPos = hPartition(irData, iStart, iEnd);
        QuickSort(irData, iStart, lPos - 1);
        QuickSort(irData, lPos + 1, iEnd);
    }
    int QuickSelection(vector<int> &irData, size_t iStart, size_t iEnd, size_t k)
    {
        if (iStart >= iEnd)
            return iStart;

        size_t lPivot = hPartition(irData, iStart, iEnd);
        if (lPivot == k)
        {
            return irData[lPivot];
        }
        else if (lPivot > k)
        {
            return QuickSelection(irData, iStart, lPivot, k);
        }
        else
        {
            return QuickSelection(irData, lPivot + 1, iEnd, k);
        }
    }
    // All data in irData is >=0 && < iMax 
    void BucketSort(vector<int> &irData, int iMax)
    {
        vector<int> lBucket(iMax, 0);
        // for (int i = 0; i < iMax; i++)
        //     lBucket[i] = 0;
        for (auto &it : irData)
        {
            lBucket[it]++;
        }
        irData.clear();
        for(size_t i = 0 ; i < iMax; i++)
        {
            size_t lCount  = lBucket[i];
            while(lCount > 0)
            {
                irData.push_back(i);
                lCount--;
            }  
        }
    }
    void RadixSort(vector<int> &irData)
    {
        int lBit = hGetMaxBits(irData);
        queue<int> lBulkets[10];
        int lBase  = 1 ; 
        // from low bit to high bit. 
        for(int i = 0 ; i < lBit; i++)
        {
            // push into bulket. 
            for(auto& it : irData)
            {
                int lBulkPos = (it / lBase) % 10; 
                lBulkets[lBulkPos].push(it);
            }
            // Insert with reodered sequence. 
            irData.clear();
            for( int i = 0; i < 10 ; i++)
            {
                while (!lBulkets[i].empty())
                {
                    irData.push_back(lBulkets[i].front());
                    lBulkets[i].pop();
                }
            }
            lBase  = lBase * 10;
        }
    }

private:
    int hGetMaxBits(vector<int>& irData)
    {
        int lbit = 1;
        int lMax = 10;
        for(auto& it : irData)
        {
            if(it >= lMax)
            {
                lbit++;
                lMax *= 10;
            }
        }
        return lbit;
    }
    size_t hPartition(vector<int> &irData, size_t iStart, size_t iEnd)
    {
        int lPivot = irData[iStart];
        size_t lLow = iStart, lHigh = iEnd;

        while (lLow < lHigh)
        {
            while (irData[lHigh] > lPivot)
            {
                lHigh--;
            }
            if (lLow < lHigh)
                swap(irData[lLow++], irData[lHigh]);

            while (irData[lLow] < lPivot)
            {
                lLow++;
            }
            if (lLow < lHigh)
                swap(irData[lLow], irData[lHigh--]);
        }
        irData[lLow] = lPivot;
        return lLow;
    }
};

void testAcceptance()
{
    vector<int> lDataVec = {7, 0, 8, 2, 9, 6, 3, 4, 5, 1};

    Solution S1;
    for (size_t i = 0; i < lDataVec.size(); i++)
    {
        size_t lpos = S1.QuickSelection(lDataVec, 0, lDataVec.size() - 1, i);
        assert(lpos == i);
    }

    vector<int> lTmp;
    S1.MergeSort(lDataVec, lTmp, 0, lDataVec.size() - 1);

    for (int i = 0; i < lDataVec.size(); i++)
    {
        assert(lDataVec[i] == i);
    }
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(lDataVec.begin(), lDataVec.end(), g);
    S1.QuickSort(lDataVec, 0, lDataVec.size() - 1);
    for (int i = 0; i < lDataVec.size(); i++)
    {
        assert(lDataVec[i] == i);
    }
    lTmp.clear();
    lTmp = {2, 1, 3, 2,3,4,4,4,4,3};
    S1.BucketSort(lTmp, 5);
    for(auto& it: lTmp)
        cout<< it  << "\t";
}

void RadixSortTest()
{
    vector<int> lDataVec;
    for( int i = 0 ; i < 100; i++)
    {
        lDataVec.push_back(rand() % 1000);
    }
    Solution S1; 
    S1.RadixSort(lDataVec);
    for(int i = 1; i < lDataVec.size();i++)
    {
        assert(lDataVec[i] >= lDataVec[i-1]);
    }
    cout<< "RadixSort Pass" <<endl;
}
int main()
{
    //testAcceptance();
    RadixSortTest();
    return 0;
}