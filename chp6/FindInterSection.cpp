#include <vector>
#include <iostream>
#include <random>
using namespace std;

vector<int> FindIntersection(vector<int>& irData1, vector<int> &irData2)
{
   vector<int> lResult; 
   size_t i = 0 , j = 0;
   while(i < irData1.size() && j < irData2.size())
   {
       if(irData1[i] == irData2[i])
       {
           lResult.push_back(irData1[i]);
           i++; 
           j++;
       }else if(irData1[i]  > irData2[j])
       {
           j++;
       }
       else
       {
           i++;
       }
   }
   return lResult;
}
int main()
{
    std::random_device rd;
    std::mt19937 g(rd() % 10);
    vector<int> lData1; 
    for(int i = 0 ; i < 5; i++ )
    {
        int tmp = g()%10;
        if(std::find(lData1.begin(),lData1.end(),tmp ) == lData1.end())
            lData1.push_back(tmp);
    }
    std::sort(lData1.begin(), lData1.end());

    vector<int> lData2; 
    for(int i = 0 ; i < 20; i++ )
    {
        int tmp = g()%10;
        if(std::find(lData2.begin(),lData2.end(),tmp ) == lData2.end())
            lData2.push_back(tmp);
        
    }
    std::sort(lData2.begin(), lData2.end());
    
    auto lResult  = FindIntersection(lData1, lData2);
    return 0 ; 
}