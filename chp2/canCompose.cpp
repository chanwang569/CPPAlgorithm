#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;
bool chp2_CanCompose(string& newspaper, string& message )
{
    if(newspaper.length() < message.length())
    {
        return false;
    }
    unordered_map<char,int> lHashMap;
    for(auto it: newspaper)
    {
        lHashMap[it]++;
    }
    for(auto it: message)
    {
        if(lHashMap.count(it) == 0 || --lHashMap[it]<0)
            return false;
    }
    return true;
}
void case1()
{
    string newspaper ="abc";
    string message = "d";
    bool lResult = chp2_CanCompose(newspaper, message);
    assert(lResult == false);
}
void case2()
{
    string newspaper ="abc";
    string message = "aa";
    bool lResult = chp2_CanCompose(newspaper, message);
    assert(lResult == false);
}
void case3()
{
    string newspaper ="aabbbccccc";
    string message = "abc";
    bool lResult = chp2_CanCompose(newspaper, message);
    assert(lResult == true);
}

int main()
{
   case1();
   case2();
   case3();
    return 0;
}