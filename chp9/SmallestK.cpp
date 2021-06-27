#include<vector>
using namespace std;
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) 
    {
        int low = 0, high = arr.size() - 1;

        while (low <=high)
        {
            while (arr[low] < k && low <= high)
            {
                low++;
            }
            while (arr[high] > k && low<= high)
            {
                high--;
            }
            if(low < high)
            {
                int tmp = arr[low];
                arr[low] = arr[high];
                arr[high] = tmp;
                low++; high--;
            }else{
                break;
            }
        }     
    
        vector<int> lResult; 
        for(int i = 0 ; i < low; i++)
        {
            lResult.push_back(arr[i]);
        }
        return lResult;
    }
};

int main()
{
    Solution S1;
    vector<int> nums ={1,3,5,7,2,4,6,8};
    auto result = S1.smallestK(nums, 4 );
    return 0;
}