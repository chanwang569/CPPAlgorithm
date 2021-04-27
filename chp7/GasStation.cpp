#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> lArray(gas.size(), 0);
        int total = 0;
        for (size_t i = 0; i < gas.size(); i++)
        {
            lArray[i] = gas[i] - cost[i];
            total += lArray[i];
        }
        if(total < 0 )
            return -1;
       
        int lIndex = 0; 
        int left = 0; 
        for(int i = 0 ; i < lArray.size(); i++)
        {
            left += lArray[i];
            if(left < 0)
            {
                lIndex = i+1;
                left = 0;
            }
        }
        return lIndex;
    }
};

void case0()
{
    vector<int> gas= {1,2,3,4,5};
    vector<int> station = {3,4,5,1,2};
    Solution S1;
    auto result = S1.canCompleteCircuit(gas, station);
    assert(result == 3);
}
int main()
{
    case0();
    return 0;
}

