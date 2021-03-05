#include<iostream>
#include<vector>
using namespace std;
void RemoveDulicateElement(vector<int>& irVec, int iValue)
{
    for(auto it = irVec.begin(); it != irVec.end(); it++)
    {
        if(*it == iValue)
        {
            it = irVec.erase(it);
            it--;
        }
    }
}
void RemoveElementV2(vector<int>& irVec, int iValue)
{
    size_t lLastPos = irVec.size() -1;
    for(size_t i = 0; i < irVec.size() && i< lLastPos; i++)
    {
        if(irVec[i] == iValue)
        {
            irVec[i] = irVec[lLastPos];
            irVec.pop_back();
            i--;
            lLastPos--;
        }
    }
}
void case_acceptance()
{
    vector<int> lVec ={ 0,4,4,0,0,2,4,4};
    RemoveElementV2(lVec,4);
    assert(lVec.size()==4);
}
int main()
{
    case_acceptance();
    return 0;
}