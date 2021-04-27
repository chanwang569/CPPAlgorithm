#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    int returnKthPrime(int n)
    {
        vector<int> lPrimes = {2};
        int v = 3;
        while (lPrimes.size() < n )
        {
            bool lIsPrime = true;
            for (auto it = lPrimes.begin(); it != lPrimes.end(); it++)
            {
                if (v % *it == 0)
                {
                    lIsPrime = false;
                }
            }
            if (lIsPrime)
                lPrimes.push_back(v);

            v += 2;
        }
        return *(lPrimes.rbegin());
    }
};

Solution ::Solution(/* args */)
{
}

Solution ::~Solution()
{
}

int main()
{
    Solution S1;
    assert(S1.returnKthPrime(1) == 2);
    assert(S1.returnKthPrime(2) == 3);
    assert(S1.returnKthPrime(3) == 5);
    assert(S1.returnKthPrime(4) == 7);
    assert(S1.returnKthPrime(5) == 11);
    cout << endl;
}