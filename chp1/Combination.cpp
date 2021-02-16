#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct S {
 // three-bit unsigned field,
 // allowed values are 0...7
 unsigned int b : 3;
};
void testBitField()
{
    S s = {0x7};
    std::cout << s.b << '\n';
    ++s.b; // store the value 7 in the bit field
    std::cout << s.b << '\n';
    ++s.b; // the value 8 does not fit in this bit field
    std::cout << s.b << '\n'; // formally implementation-defined, typically 0
}

 void Combination(string& irStr, size_t iPos, vector<string>& orResult)
{
    if(iPos == irStr.length() - 1 )
    {
        string lTmp;
        lTmp.append(1,irStr[iPos]);
        orResult.emplace_back(lTmp);
        return; 
    }
    Combination(irStr, iPos + 1, orResult);
    
    size_t lResultSize = orResult.size();
    for(auto i = 0; i < lResultSize; i ++ )
    {
        string lTmp = orResult[i];
        lTmp.append(1,irStr[iPos]);
        orResult.emplace_back(lTmp);
    } 
    string lTmp;
    lTmp.append(1,irStr[iPos]);
    orResult.emplace_back(lTmp);
}

int main ()
{
    string lStr("abc");
    std::vector<bool> lbVec(lStr.length(), false);
    std::vector<string> lResult; 
    Combination(lStr, 0 , lResult);
    for(auto it = lResult.begin(); it !=lResult.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;   
}