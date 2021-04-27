#include<vector>
using namespace std;


class Solution {
public:
    int numTrees(int n) {
        vector<int> lDP(n + 1, 0); 
        lDP[0] = 1;
        lDP[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 0; j < i; j++)
                lDP[i] += lDP[j]*lDP[i - j - 1];
        }
        return lDP[n];
    }
};

int main()
{
    Solution S1; 
   auto lResult =  S1.numTrees(3);

}