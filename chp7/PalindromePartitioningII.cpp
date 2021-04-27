#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
int minCut(string s) {
    if(s.empty()) return 0;

    size_t len = s.size();
    vector< vector<bool> > lPalind(len, vector<bool>(len, false)); // lPalind[j][i]  means s[j] ~s[i] is Palindrome
    vector<int> lMinCut(len, 0);

    for(size_t i = 0 ; i < len; i++)
    {
        lMinCut[i] = i;    
        for(int j = 0; j<= i; j++)
        {
            if(s[i] == s[j] && (i - j < 2 || lPalind[j+1][i-1]))
            {
                lPalind[j][i] = true;
                lMinCut[i] = (j == 0) ? 0 : min(lMinCut[i], lMinCut[j - 1] + 1);
            } 
        }
    }
    return lMinCut[len -1];
}

private:
}; 

int main()
{
    string s("aab");
    Solution S1;

    int lcount  = S1.minCut(s);
    cout<< lcount << endl;
  
    cout<< endl;
}