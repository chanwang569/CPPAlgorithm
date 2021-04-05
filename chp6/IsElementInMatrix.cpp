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
    bool isElementInMatrix(vector<vector<int> > &irMatrix, int iValue)
    {
        if(irMatrix.size()== 0 )
            return false; 
        size_t m = irMatrix[0].size() - 1 ;
        size_t n = irMatrix.size() -1;
        size_t i = n, j = 0;
        while(i >= 0 && j <= m )
        {
            if(irMatrix[i][j] == iValue)
            {
                return true;
            }else if(irMatrix[i][j] < iValue)
            {
                j++;
            }else
            {
                i--;
            }
        }
        return false; 
    }

private:
};

void testAcceptance()
{
    vector<vector<int> > lMatrix; 
    vector<int> lVec1 = {1, 5, 10 ,20};
    vector<int> lVec2 = {2, 6 , 11 ,30 };
    vector<int> lVec3 = {7, 9, 12, 40};
    vector<int> lVec4 = {8, 15, 31 ,41};
    lMatrix.push_back(lVec1);
    lMatrix.push_back(lVec2);
    lMatrix.push_back(lVec3);
    lMatrix.push_back(lVec4);
    Solution S1;
    for(size_t i = 0; i < lMatrix.size(); i++)
    {
        for(size_t j = 0 ; j < lMatrix[i].size(); j++)
        {
            assert(S1.isElementInMatrix(lMatrix, lMatrix[i][j]) == true);
        }
    }
}
    int main()
    {
        testAcceptance();
        return 0;
    }