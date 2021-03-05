#include <vector>
using namespace std;

int Partition(vector<int>& irData, int k)
{
    int low = 0, high = irData.size() - 1;
    while (low <=high)
    {
        while (irData[low] < k && low <= high)
        {
            low++;
        }
        while (irData[high] >= k && low<= high)
        {
            high--;
        }
        if(low < high)
        {
            int tmp = irData[low];
            irData[low] = irData[high];
            irData[high] = irData[low];
            low++; high--;
        }else{
            break;
        }     
    }
    return low;
}
void case_acceptance()
{
    vector<int> lVec = {1,3, 5, 7, 9};
    auto lResult = Partition(lVec,5);
    assert(lResult ==2);
    lResult = Partition(lVec, 10);
    assert(lResult == 5);
    lResult = Partition(lVec, 0);
    assert(lResult == 0);
    vector<int> lVec2 = {3,2,2,1};
    lResult = Partition(lVec2, 2);
    assert(lResult == 1);
}
int main()
{
    case_acceptance();
    return 0;
}