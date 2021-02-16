#include <iostream>
#include <vector>
using namespace std;

void Permutation (char* pStr, char* pBegin)
{
    assert(pStr);
    assert(pBegin);
    if(*pBegin=='\0')
    {
        printf("%s\n", pStr);
    } 
    for(char* lpChar = pBegin; *lpChar !='\0'; lpChar++)
    {
        swap(*lpChar, *pBegin); // Keep items before pBegin not changing, this is where the magic happens!
        Permutation(pStr, pBegin + 1); // Process the items at the right of pBegin.
        swap(*lpChar, *pBegin); // We have to change it back to restart from beginng.
    }
}
void PermutationV2 (char* pStr, char* pBegin)
{
    assert(pStr);
    assert(pBegin);
    if(*pBegin=='\0')
    {
        printf("%s\n", pStr);
    } 
    for(char* lpChar = pBegin; *lpChar !='\0'; lpChar++)
    {
        char tmp = *lpChar;
        *lpChar = *pBegin;
        *pBegin = tmp;
        PermutationV2(pStr, pBegin + 1);
        tmp = *lpChar;
        *lpChar = *pBegin;
        *pBegin = tmp;
    }
}
void PermutationV3(string& iStr, size_t iPos)
{
    if(iPos == iStr.size())
    {
        cout<< iStr<<endl;
    }
    for(size_t i = iPos ; i < iStr.size();i++)
    {
        if(i != iPos)
        {
             swap(iStr[i], iStr[iPos]);
        }
        PermutationV3(iStr, iPos+1);

         if(i != iPos)
        {
             swap(iStr[i], iStr[iPos]);
        }
    }
}

void PermutationV4(string& iStr, size_t iPos, vector<string>& irResult)
{
    if(iPos == iStr.size())
    {
        irResult.push_back(iStr);
    }
    for(size_t i = iPos ; i < iStr.size();i++)
    {
        if(i != iPos)
        {
             swap(iStr[i], iStr[iPos]);
        }
        PermutationV3(iStr, iPos+1);

         if(i != iPos)
        {
             swap(iStr[i], iStr[iPos]);
        }
    }
}
void testSwap()
{
    char lA[] = "ab";
    char* p = lA;
    char* q = lA+ 1;
    swap(*p, *q) ;
    printf("*p\t: %c", *p);
    printf("\n*q\t: %c", *q);

    printf("\np\t: %c", p);
    printf("\nq\t: %c", q);

}
int main ()
{
    //char lA[] = "a";
    char lA[] = "abc";
    char* p = lA, *q= lA;
    //Permutation(p, q);
    //Permutation(lA, lA);
    //PermutationV2(lA, lA);
    string lStr= "abc";
    //PermutationV3(lStr, 0);
    vector<string> lResultVec;
    PermutationV4(lStr, 0,lResultVec);
    //for(vector<string>::iterator  it  = lResultVec.begin(); it != lResultVec.end(); it++)
    for( auto it = lResultVec.begin(); it !=lResultVec.end(); it++)
    {
        cout<< *it <<endl;
    }
    //testSwap();
    return 0;
}
