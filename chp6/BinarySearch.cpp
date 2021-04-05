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
    size_t BinarySearch(vector<int> &irData, size_t low, size_t high, int value)
    {
        while (low <= high)
        {
            size_t mid = (low + high) >> 1;
            if (irData[mid] == value)
            {
                return mid;
            }
            else if (irData[mid] < value)
            {
                return BinarySearch(irData, mid+1, high, value);
            }
            else
            {
                return BinarySearch(irData, 0, mid -1, value);
            }
        }
        return INT_MAX;
    }
    size_t BinarySearch2(vector<int>& irData, size_t low, size_t high, int value)
    {
        while (low <= high)
        {
            size_t mid = (low + high) >> 1;
            if(irData[mid] == value)
            {
                return mid;
            }
            else if (irData[mid] < value)
            {
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return INT_MAX;     
    }

private:
};

void testAcceptance()
{
    vector<int> lDataVec = {2, 3, 5, 8, 13, 21, 34, 55, 89};

    Solution S1;
    assert(S1.BinarySearch(lDataVec, 0, lDataVec.size() -1, 2 ) == 0);
    assert(S1.BinarySearch(lDataVec, 0, lDataVec.size() -1, 3 ) == 1);
    assert(S1.BinarySearch(lDataVec, 0, lDataVec.size() -1, 5 ) == 2);
    assert(S1.BinarySearch(lDataVec, 0, lDataVec.size() -1, 8 ) == 3);
    assert(S1.BinarySearch(lDataVec, 0, lDataVec.size() -1, 13 ) == 4);
    assert(S1.BinarySearch(lDataVec, 0, lDataVec.size() -1, 21 ) == 5);
    assert(S1.BinarySearch(lDataVec, 0, lDataVec.size() -1, 34 ) == 6);
    assert(S1.BinarySearch(lDataVec, 0, lDataVec.size() -1, 55 ) == 7);
    assert(S1.BinarySearch(lDataVec, 0, lDataVec.size() -1, 89 ) == 8);
    assert(S1.BinarySearch(lDataVec, 0, lDataVec.size() -1, 4 ) == INT_MAX);
    assert(S1.BinarySearch(lDataVec, 0, lDataVec.size() -1, 9 ) == INT_MAX);
    assert(S1.BinarySearch(lDataVec, 0, lDataVec.size() -1, 23 ) == INT_MAX);
    assert(S1.BinarySearch(lDataVec, 0, lDataVec.size() -1, 56 ) == INT_MAX);
    assert(S1.BinarySearch(lDataVec, 0, lDataVec.size() -1, 99 ) == INT_MAX);
}
void testAcceptance2()
{
    vector<int> lDataVec = {2, 3, 5, 8, 13, 21, 34, 55, 89};

    Solution S1;
    assert(S1.BinarySearch2(lDataVec, 0, lDataVec.size() -1, 2 ) == 0);
    assert(S1.BinarySearch2(lDataVec, 0, lDataVec.size() -1, 3 ) == 1);
    assert(S1.BinarySearch2(lDataVec, 0, lDataVec.size() -1, 5 ) == 2);
    assert(S1.BinarySearch2(lDataVec, 0, lDataVec.size() -1, 8 ) == 3);
    assert(S1.BinarySearch2(lDataVec, 0, lDataVec.size() -1, 13 ) == 4);
    assert(S1.BinarySearch2(lDataVec, 0, lDataVec.size() -1, 21 ) == 5);
    assert(S1.BinarySearch2(lDataVec, 0, lDataVec.size() -1, 34 ) == 6);
    assert(S1.BinarySearch2(lDataVec, 0, lDataVec.size() -1, 55 ) == 7);
    assert(S1.BinarySearch2(lDataVec, 0, lDataVec.size() -1, 89 ) == 8);
    assert(S1.BinarySearch2(lDataVec, 0, lDataVec.size() -1, 4 ) == INT_MAX);
    assert(S1.BinarySearch2(lDataVec, 0, lDataVec.size() -1, 9 ) == INT_MAX);
    assert(S1.BinarySearch2(lDataVec, 0, lDataVec.size() -1, 23 ) == INT_MAX);
    assert(S1.BinarySearch2(lDataVec, 0, lDataVec.size() -1, 56 ) == INT_MAX);
    assert(S1.BinarySearch2(lDataVec, 0, lDataVec.size() -1, 99 ) == INT_MAX);
}


int main()
{
    testAcceptance();
    testAcceptance2();
    return 0;
}