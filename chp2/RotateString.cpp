#include <string>
using namespace std;
void RotateString(string& irString, size_t iPos)
{
    if(irString.length() == 0 || iPos % irString.length() ==0) 
        return; 
    size_t lMoveCount = iPos % irString.length(); 
    size_t lKept = irString.length() - lMoveCount; 
    string lReveredStr(irString, lKept, lMoveCount);
    irString.erase(irString.begin()+ lKept);
    irString.insert(0, lReveredStr);
}
void case_acceptance()
{
    string lStr = "abcdefg";
    string lStr2(lStr);
    RotateString(lStr2, 0);
    assert(lStr2.compare(lStr) == 0);

    lStr2 = lStr;
    RotateString(lStr2, 1);
    assert(lStr2.compare("gabcdef") == 0);
}
int main()
{
    case_acceptance();

    return 0;
}