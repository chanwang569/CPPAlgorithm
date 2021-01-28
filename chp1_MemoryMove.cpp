#include <iostream>
using namespace std;

void* memmove(void *dest, const void *src, size_t n)
{
    if(n <0 ) 
        return nullptr; 
    
    if (dest  == const_cast<void*>(src))
    {
        return dest;
    }
    char* p1 = static_cast<char*>(dest);
    const char* p2 = reinterpret_cast<const char*>(src); 

    if (p1 < p2)
    {
        for (int i = 0; i < n; i++)
        {
            *p1 = *p2;
            p1++;
            p2++;
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            *(p1 + i) = *(p2 + i);
            p1--;
            p2--;
        }
        p1 = p1 + n -1;
    }
    return  p1;
}
void test()
{
    int i[5] ={0, 1, 2, 3, 4};
    int* p = i;
    cout << "*p++" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout<< *p++ <<"\t"; // *优先级高于++
    }
    int *p1 = i ;
    cout << "\n"<<"*++p" <<"\n";
    
    for(int i = 0; i < 4; i++)
    {
        cout<< *++p1 << "\t";
    }
    cout << "\n" << "The End!" << endl;
}
int main()
{
    
    return 0;
}