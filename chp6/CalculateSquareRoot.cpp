#include <iostream>
#include <cstdlib>
using namespace std;
const double precision = 0.00001; 
class Solution
{
public:
    
double CalculateSquareRoot(double iData)
{
     if(iData == 0 || iData == 1)
        return iData;
    if(iData < 0)
        return -1; 
   
    if(iData < 1)
    {
        return hCalculateSquareRoot(iData, iData, 1);
    }else
    {
        return hCalculateSquareRoot(iData, 1, iData);
    }
    
}
private:
double hCalculateSquareRoot(double iData, double lowbound, double highbound)
    {
        double square = (lowbound + highbound) /2 ; 
        if(abs(square * square - iData) < precision)
        {
            return square;
        }else if(square * square - iData > 0 )
        {
            return hCalculateSquareRoot(iData, lowbound, square);
        }else
        {
            return hCalculateSquareRoot(iData, square, highbound);
        }
    }
};

void testAcceptance()
{
    Solution S1;
    double lResult = S1.CalculateSquareRoot(2);
    cout << endl;
}
    int main()
    {
        testAcceptance();
        return 0;
    }