#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

bool isPermutation(string& iStr1, string& iStr2)
{
    if(iStr1.size() != iStr2.size())
        return false;
    unordered_map<char,int> lHashTable1; 
    for(auto it = iStr1.begin();it != iStr1.end(); it++)
    {
        lHashTable1[int(*it)]++;
    }
    unordered_map<char,int> lHashTable2; 
    for(auto it = iStr2.begin();it != iStr2.end(); it++)
    {
        lHashTable2[int(*it)]++;
    }
    if(lHashTable1.size() != lHashTable2.size())
        return false;

    for(const auto& [key,value] : lHashTable1)
    {
        if(value != lHashTable1[key])
            return false;
    }
    return true;
}
int main()
{
    string lStr1 = "abcdefgh";
    string lStr2 = "hgfedcba";
    bool lResult = isPermutation(lStr1, lStr2);
    
    return 0;
}