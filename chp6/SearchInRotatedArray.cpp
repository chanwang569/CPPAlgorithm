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
    size_t SearchInRoatedArray(vector<int> &A, size_t l, size_t h, int iValue)
    {
        if (l > h || h > A.size())
            return INT_MAX;
        size_t m = (l + h) >> 1;

        if (A[m] == iValue)
        {
            return m;
        }
        else if (A[l] < A[m ]) // Left Side is sorted.
        {
            if (iValue >= A[l] && iValue <= A[m ])
            {
                return SearchInRoatedArray(A, l, m - 1, iValue);
            }
            else
            {
                return SearchInRoatedArray(A, m + 1, h, iValue);
            }
        }
        else
        {
            // Right Side is sorted.
            if (iValue >= A[m ] && iValue <= A[h])
            {
                return SearchInRoatedArray(A, m + 1, h, iValue);
            }
            else
            {
                return SearchInRoatedArray(A, l, m - 1, iValue);
            }
        }

        return INT_MAX;
    }

private:
};

void testAcceptance()
{
    vector<int> lDataVec = {4, 6, 1, 2, 3};

    Solution S1;
    for (size_t i = 0; i < lDataVec.size(); i++)
    {
        assert(S1.SearchInRoatedArray(lDataVec, 0, lDataVec.size() - 1, lDataVec[i]) == i);
    }
    assert(S1.SearchInRoatedArray(lDataVec, 0, lDataVec.size() - 1, 5) == INT_MAX);
}

int main()
{
    testAcceptance();
    return 0;
}