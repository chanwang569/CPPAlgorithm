#include <vector>
#include <string>
#include <set>
using namespace std;
class Solution
{
public:
    vector<string> permutation(string s)
    {
        vector<string> lResult;
        hPermutation(s, 0, lResult);
        return lResult;
    }

private:
    void hPermutation(string &s, int pos, vector<string> &orResult)
    {
        set<char> lExisting; // To handle duplicate char scenarios. 
        if (pos < s.length())
        {
            for (int i = pos; i < s.length(); i++)
            {
                if (lExisting.find(s[i]) != lExisting.end())
                    continue;// If s[i] had been placed into pos, no need to do again,otherwise, duplication happens. 
                lExisting.insert(s[i]);
                swap(s[i], s[pos]);// Place ith to the pos position. 
                hPermutation(s, pos + 1, orResult);
                swap(s[i], s[pos]);
            }
        }
        else
        {
            orResult.push_back(s);
            return;
        }
    }
};

    int main()
    {
        Solution S1;
        vector<string> lResult = S1.permutation("abb");
        assert(lResult.size() ==3);
        lResult.clear();
        lResult = S1.permutation("abc");
        assert(lResult.size() ==6);
        return 0;
    }