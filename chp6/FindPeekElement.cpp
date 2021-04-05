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
    size_t SearchInRoatedArray(vector<int> &A, size_t l, size_t h )
    {
        int m = (l + h) >>1;
        if( (m == 0 || A[m]> A[m-1]) && (A[m]> A[m+1] || m == h))
        {   
             return m;
        } else if( A[m] < A[m+1]) 
        {
            // A[m] > A[m-1] && A[m] < A[m+1] or A[m]<  A[m -1 ] && A[m] < A[m+1]
            return SearchInRoatedArray(A, m + 1, h);
        }
        else{
            // A[m] < A[m-1] && A[m] < A[m+1] 
            return SearchInRoatedArray(A, l, m - 1);
        }
        return INT_MAX;
    }
  

private:
};

void testAcceptance()
{
    vector<int> lDataVec = {1, 2, 1,3 ,4, 5 , 7, 6};

    Solution S1;
    auto result = S1.SearchInRoatedArray(lDataVec, 0 , lDataVec.size() -1 );
   assert(result == 1 || result == 6);
}


int main()
{
    testAcceptance();
    return 0;
}