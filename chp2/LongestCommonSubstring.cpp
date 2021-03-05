#include <string>
using namespace std;

int GetLongestCommonSubstring(string &iStr1, string &iStr2)
{
    int lResult = 0;
    if (iStr1.length() == 0 || iStr2.length() == 0)
        return lResult;

    for (int i = 0; i < iStr1.length(); i++)
    {
        for (int j = 0; j < iStr2.length(); j++)
        {
            int len = 0;
            while (iStr1[i + len] == iStr2[j +len] && ( j + len < iStr2.length()))
            {
                len++;
            }
            if(len > lResult)
                lResult = len;
        }
    }
    return lResult;
}

void case1_Acceptance()
{
    string lStr1 = "ABCD";
    string lStr2 = "CBCE";
    int result = GetLongestCommonSubstring(lStr1, lStr2);
    assert(result == 2);
}
void case1_Acceptance2()
{
    string lStr1 = "ABCDEFGHI";
    string lStr2 = "ADEF";
    int result = GetLongestCommonSubstring(lStr1, lStr2);
    assert(result == 3);
}

int main()
{
    case1_Acceptance();
    case1_Acceptance2();
    return 0;
}