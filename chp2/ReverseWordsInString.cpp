#include <string>
using namespace std;

size_t hFindNextSplitPos(string &irString, size_t iStartPos)
{
    for (size_t i = iStartPos; i < irString.length(); i++)
    {
        if (irString[i] == ' ' || irString[i] == ',' || irString[i] == '.')
            return i;
    }
    return -1;
}

void hSwapCharInString(string& iorString, size_t iStartPos, size_t iEndPos)
{
    if(iStartPos >= iorString.length() || iEndPos >=iorString.length() )
        return;
    while(iStartPos < iEndPos)
    {
        swap(iorString[iStartPos++],iorString[iEndPos--]);
    }
}
bool hOnlyNumber(string& irString, size_t iStartPos, size_t iEndPos)
{
     if(iStartPos >= irString.length() || iEndPos >=irString.length() )
        return false;

    for(size_t i = iStartPos; i < iEndPos; i++)
    {
        if(irString[i]>='0' && irString[i]<='9')
        {
            continue;
        }    
        else
            return false;
    }
    return true;
}
string ReverseWordsInString(string &iorString)
{
    string lResult;
    size_t lSplitPos = 0;
    size_t lStartPos = 0;
    do 
    {
        lSplitPos = hFindNextSplitPos(iorString, lStartPos);  
        if(!hOnlyNumber(iorString,lStartPos, lSplitPos - 1))
        {
            hSwapCharInString(iorString, lStartPos, lSplitPos -1);
        }
        lStartPos = lSplitPos +1;
    }while(lStartPos != -1 && lStartPos < iorString.length());

    return lResult;
}

void case0_Acceptance()
{
    string lStr = "I have 36 books, 40 pens2.";
    ReverseWordsInString(lStr);
    assert(lStr.compare("I evah 36 skoob, 40 2snep.") == 0);
}
int main()
{
    case0_Acceptance();
    return 0;
}
