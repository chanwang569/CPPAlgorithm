#include<cstring>
#include<cstdio>
#include<bitset>
#include<iostream>
using namespace std;
bool isUnique(string iStr)
{
    bitset<256> lBitSit(0);
    for(int i = 0 ; i < iStr.length(); i++)
    {
        
        if(lBitSit[int(iStr[i])])
        {
            return false;
        }
        else
        {
            lBitSit[int(iStr[i])] = 1;
        }
    }
    return true;
}
int main()
{
    string lstr = "abcdefg";
    bool lResult = isUnique(lstr);
    cout<< lstr << "\t" << lResult<< endl;
    return 0;
}