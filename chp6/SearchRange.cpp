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
    void isElementInMatrix(vector<int> &A, size_t l, size_t h, int iValue, size_t &irBegin, size_t &irEnd)
    {
        if (l > h || h > A.size())
            return;
        size_t m = (l + h) >> 1;

        if (A[m] == iValue)
        {
            if(m < irBegin)
                irBegin = m;
            if(m > irEnd || irEnd ==INT_MAX )
                irEnd = m;
            isElementInMatrix(A, l, m - 1, iValue, irBegin, irEnd);       
            isElementInMatrix(A, m+1, h, iValue, irBegin, irEnd); 
        }else if(A[m] < iValue)
        {
            isElementInMatrix(A, m+1, h, iValue, irBegin, irEnd);
        } else
        {
            isElementInMatrix(A, l, m-1, iValue, irBegin, irEnd);
        }
      
    }

private:
};

void testAcceptance()
{
    vector<int> lDataVec = {1, 2, 2, 3, 3, 3, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6};

    Solution S1;
    size_t lBegin = INT_MAX, lEnd = INT_MAX;
    S1.isElementInMatrix(lDataVec, 0, lDataVec.size() - 1, 1, lBegin, lEnd);
    assert(lBegin == 0 && lEnd == 0);
    
    lBegin = INT_MAX, lEnd = INT_MAX;
    S1.isElementInMatrix(lDataVec, 0, lDataVec.size() - 1, 2, lBegin, lEnd);
    assert(lBegin == 1 && lEnd == 2);
    
    lBegin = INT_MAX, lEnd = INT_MAX;
    S1.isElementInMatrix(lDataVec, 0, lDataVec.size() - 1, 3, lBegin, lEnd);
    assert(lBegin == 3 && lEnd == 5);
    
    lBegin = INT_MAX, lEnd = INT_MAX;
    S1.isElementInMatrix(lDataVec, 0, lDataVec.size() - 1, 4, lBegin, lEnd);
    assert(lBegin == INT_MAX && lEnd == INT_MAX);

    lBegin = INT_MAX, lEnd = INT_MAX;
    S1.isElementInMatrix(lDataVec, 0, lDataVec.size() - 1, 5, lBegin, lEnd);
    assert(lBegin == 6 && lEnd == 10);

    lBegin = INT_MAX, lEnd = INT_MAX;
    S1.isElementInMatrix(lDataVec, 0, lDataVec.size() - 1, 6, lBegin, lEnd);
    assert(lBegin == 11 && lEnd == 16);

    lBegin = INT_MAX, lEnd = INT_MAX;
    S1.isElementInMatrix(lDataVec, 0, lDataVec.size() - 1, 7, lBegin, lEnd);
    assert(lBegin == INT_MAX && lEnd == INT_MAX);
}
    int main()
    {
        testAcceptance();
        return 0;
    }