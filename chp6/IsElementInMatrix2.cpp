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
        size_t l = 0; 
        size_t h = irMatrix.size() * irMatrix[0].size() - 1; 
        size_t count = irMatrix[0].size();
        while (l <= h && h < count* irMatrix.size())
        {
            size_t m = (l + h )/2; 
            if(irMatrix[ m / count][m % count] == iValue)
            {
                return true;
            }else if( irMatrix[ m / count][m % count] > iValue)  
            {
                h  = m - 1;
            }else
            {
                l = m + 1;
            }  
        }
        
        return false; 
    }

private:
};

void testAcceptance()
{
    vector<vector<int> > lMatrix; 
    vector<int> lVec1 = {1, 3, 5, 7};
    vector<int> lVec2 = {10, 11 , 16, 20};
    vector<int> lVec3 = {23, 30, 34, 50};
    
    lMatrix.push_back(lVec1);
    lMatrix.push_back(lVec2);
    lMatrix.push_back(lVec3);

    Solution S1;
    for(size_t i = 0; i < lMatrix.size(); i++)
    {
        for(size_t j = 0 ; j < lMatrix[i].size(); j++)
        {
            assert(S1.isElementInMatrix(lMatrix, lMatrix[i][j]) == true);
        }
    }
    assert(S1.isElementInMatrix(lMatrix, 0 ) == false);
    assert(S1.isElementInMatrix(lMatrix, 12 ) == false);
    assert(S1.isElementInMatrix(lMatrix, 51 ) == false);
}
    int main()
    {
        testAcceptance();
        return 0;
    }