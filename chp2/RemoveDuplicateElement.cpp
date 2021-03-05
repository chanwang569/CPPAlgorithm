#include<iostream>
#include<vector>
using namespace std;
size_t RemoveDulicateElement(vector<int>& irVec)
{
    if(irVec.empty())
        return 0;
    size_t lCount = 0;
    for(size_t i = 1 ; i < irVec.size(); i++)
    {
        if(irVec[i] != irVec[lCount])
        {
            irVec[++lCount] = irVec[i];
        }
    }
    irVec.erase(irVec.begin() + lCount+1, irVec.end());

    return lCount + 1 ;
}

void case_acceptance()
{
    vector<int> lVec ={ 1,1,1,2,2,3,3,3,3,3,3,4,5,5,5,6,6,6,6};
    auto lLength = RemoveDulicateElement(lVec);
    assert(lLength==6);
}
int main()
{
    case_acceptance();
    return 0;
}