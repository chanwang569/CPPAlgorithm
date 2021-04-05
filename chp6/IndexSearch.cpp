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
    size_t BinarySearch(vector<int> &irData, size_t low, size_t high )
    {
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (irData[mid] == mid)
            {
                return mid;
            }
            else if (irData[mid] < mid)
            {
                if(mid + 1  > high) 
                    return INT_MAX; 
                return BinarySearch(irData, mid+1, high);
            }
            else
            {
                if(mid == 0 )
                    return INT_MAX;
                return BinarySearch(irData, 0, mid - 1);
            }
        }
        return INT_MAX;
    }
  

private:
};

void testAcceptance()
{
    vector<int> lDataVec = {-7, -2 , 0 , 3 , 7, 9, 10, 12, 13};

    Solution S1;
   assert(S1.BinarySearch(lDataVec, 0 , lDataVec.size() -1 ) == 3);
}


int main()
{
    testAcceptance();
    return 0;
}