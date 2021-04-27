#include<iostream>
using namespace std;
class  Solution
{
private:
    /* data */
public:
     Solution
    (/* args */);
    ~ Solution();
    long long CalculateFibonaciiDC(unsigned int n)
    {
        if(n == 0  || n ==1)
            return n;
        return CalculateFibonaciiDC(n -1) + CalculateFibonaciiDC(n -2);
    }
    long long CalculateFibonaciiDP(unsigned int n)
    {
        if(n == 0 || n ==1 )
            return n ;
        long long a = 0, b = 1, sum = 0;

        for(int i = 0; i < n - 1 ; i++)
        {
            sum  = a + b;
            a = b;
            b = sum;  
        }
        return sum; 
    }
};

 Solution
:: Solution
(/* args */)
{
}

 Solution
::~ Solution
()
{
}

int main()
{
    Solution S1;
    for(int i = 0; i < 20; i++)
    {
        assert(S1.CalculateFibonaciiDC(i) == S1.CalculateFibonaciiDP(i));
        cout<< S1.CalculateFibonaciiDP(i) << "\t";
    }
    cout<< endl;
}