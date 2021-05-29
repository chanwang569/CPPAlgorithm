#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
class Solution
{
public:
    vector<vector<string> > solveNQueens(int n)
    {
        vector<vector<string> > lResult;
        vector<int> lQueens(n, -1);
        unordered_set<int> lcolumns;
        unordered_set<int> lDiagonals;
        unordered_set<int> lAntiDiagonals;
        hBackTracing(n, 0, lQueens, lcolumns, lDiagonals, lAntiDiagonals, lResult);
        return lResult;
    }

private:
    void hBackTracing(int N, int index, vector<int> &irQueens, unordered_set<int> &irColumns, unordered_set<int> &irDiagonals,
                      unordered_set<int> &irAntiDiagonals, vector<vector<string> > &orResult)
    {
        if (index < N)
        {
            // Put one item in one row.
            for (int i = 0; i < N; i++)
            {
                if (irColumns.find(i) != irColumns.end())
                    continue; // same column found
                int lDiagValue = index - i;
                if (irDiagonals.find(lDiagValue) != irDiagonals.end())
                    continue;
                int lAntiDiagonalValue = index + i;
                if (irAntiDiagonals.find(lAntiDiagonalValue) != irAntiDiagonals.end())
                    continue;

                // find a place which is "placable"
                irQueens[index] = i;
                irColumns.insert(i);
                irDiagonals.insert(lDiagValue);
                irAntiDiagonals.insert(lAntiDiagonalValue);
                hBackTracing(N, index + 1, irQueens, irColumns, irDiagonals, irAntiDiagonals, orResult);

                // pop up.
                irQueens[index] = -1;
                irColumns.erase(i);
                irDiagonals.erase(lDiagValue);
                irAntiDiagonals.erase(lAntiDiagonalValue);
            }
        }
        else
        {
            //prepare result.
            orResult.push_back(hGenerateResult(irQueens));
        }
    }

    vector<string> hGenerateResult(vector<int> &irQueens)
    {
        vector<string> lResult;
        for (int i = 0; i < irQueens.size(); i++)
        {
            string lCandidate(irQueens.size(), '.');
            lCandidate[irQueens[i]] = 'Q';
            lResult.push_back(lCandidate);
        }
        return lResult;
    }
};

int main()
{
    Solution S1;
    auto result = S1.solveNQueens(4);
    return 0;
}