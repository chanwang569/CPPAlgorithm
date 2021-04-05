#include<queue>
#include<iostream>
#include <random>
using namespace std;
template<typename T>
void print_queue(T& q) { // NB: pass by value so the print uses a copy
    while(!q.empty()) {
        std::cout << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';
}
int kthLargestValue(priority_queue<int, vector<int>,std::greater<int> >& lHeap, int irData, int k, int& irReturnValue )
{
    if(lHeap.size() < k)
    {
        lHeap.push(irData);
        if(lHeap.size() == k )
        {
            irReturnValue = lHeap.top();
            return 0;
        }
        return -1; 
    }else
    {
        if(irData > lHeap.top())
        {
            lHeap.pop();
            lHeap.push(irData);
        }
        irReturnValue = lHeap.top();
        return 0; 

    }
    
   
}
int main()
{
    priority_queue<int, vector<int>,std::greater<int> > lHeap; 
    const auto data = {1,8,5,6,3,4,0,9,7,2};
   
    for( int n : data )
    {
        int lResult = 0; 
        if(kthLargestValue(lHeap, n, 1, lResult) == 0)
        {
           
            cout<< lResult << "\t";
        } 
       
    }
    cout << endl; 
    return 0; 
}