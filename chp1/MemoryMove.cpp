#include <iostream>
using namespace std;


void* memmoveV1(void *dest, const void *src, size_t n)
{
    if(n <0 ) 
        return nullptr; 
    
    if (dest  == const_cast<void*>(src))
    {
        return dest;
    }
    char* p1 = static_cast<char*>(dest);
    // reinterpret_cast is required since we need const void* -> const char* 
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
// To test the priority of ++ vs. * 
// Result: * has high priority than ++ or --
void testOperator()
{
    int i[5] ={0, 1, 2, 3, 4};
    int* p = i;
    cout << "*p++" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout<< *p++ <<"\t"; // * has high priority than ++
    }
    int *p1 = i ;
    cout << "\n"<<"*++p" <<"\n";
    
    for(int i = 0; i < 4; i++)
    {
        cout<< *++p1 << "\t";
    }
    cout << "\n" << "The End!" << endl;
}
// Conclusion: Memory allocate: Big address to Small address.
void testMemoryAllocateDirection()
{
    int i[5] ={0, 1, 2, 3, 4};
    cout<< "&i[4]:\t" << & i[4] <<endl;//&i[4]:  0x7ffee4f3a830
    cout<< "&i[3]:\t" << & i[3] <<endl;//&i[3]   0x7ffee4f3a82c
}

void testDatatypeSize()
{
    cout<< "sizeof(char):\t" << sizeof(char)<<endl;//sizeof(char):   1
    cout<<"sizeof(int):\t" << sizeof(int) << endl;// sizeof(int):    4

}
void* memmoveV2(void *dest, const void *src, size_t n)
{
     char* d = static_cast<char*>(dest);
    // reinterpret_cast is required since we need const void* -> const char* 
    const char* s = reinterpret_cast<const char*>(src);
    if(dest < src )
    {
        int i  = 0 ;
        while( i++ < n)
        {
            *d++  = *s++;
        }
        d = d - n;
    }else 
    {
        d +=n;
        s += n;
        while(n-- > 0)
        {
            *--d = * --s;
         }
    }
    return d;
}
void CaseAccept()
{
    char lCharArray[] = {'z','z','z','a','b', 'c', 'd', 'e', 'f', 'g' ,'z','z','z'};
    char lTarget[7]={'z','z','z','z','z','z','z'};
    //void* lResult = memmoveV2(lTarget, lCharArray, 7);
    //void* lResult = memmoveV2(lCharArray, lCharArray+3, 7);
    void* lResult = memmoveV2(lCharArray+5, lCharArray+3, 7);
    char* lcharResult =static_cast<char*>(lResult);

    cout<< "Result:"<<endl ;
    for(size_t i = 0; i < 7; i++)
    {
         cout<< *(lcharResult + i) << "\t"; 
    }
    cout<< endl;
}
//other ref:
//https://student.cs.uwaterloo.ca/~cs350/common/os161-src-html/doxygen/html/memmove_8c_source.html

int main()
{
    //testMemoryAllocateDirection();
    //testDatatypeSize();

    CaseAccept();
    return 0;
}