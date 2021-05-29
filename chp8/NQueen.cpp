#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();
        auto queens = vector<int>(n, -1); // store queen in ith row Queen's index. Each row can only have 1 queen so that 1 demision is enough
        auto columns = unordered_set<int>(); // queens' column
        auto diagonals1 = unordered_set<int>(); // queens' diagonal line 
        auto diagonals2 = unordered_set<int>();// queens' anti-diagonal line 
        backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
        return solutions;
    }

    void backtrack(vector<vector<string>> &solutions, vector<int> &queens, int n, 
    int row, unordered_set<int> &columns, unordered_set<int> &diagonals1, unordered_set<int> &diagonals2) {
        if (row == n) {
            // for preparing result only. n is out of size!
            vector<string> board = generateBoard(queens, n);
            solutions.push_back(board);
        } else {
            // Core logic 
            for (int i = 0; i < n; i++) {
                if (columns.find(i) != columns.end()) {
                    continue;
                }
                int diagonal1 = row - i; // abs(row - column ) is same
                if (diagonals1.find(diagonal1) != diagonals1.end()) {
                    continue;
                }
                int diagonal2 = row + i; // row + column is same
                if (diagonals2.find(diagonal2) != diagonals2.end()) {
                    continue;
                }

                queens[row] = i;
                columns.insert(i);
                diagonals1.insert(diagonal1);
                diagonals2.insert(diagonal2);
               
                // recursion
                backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
               
                //back tracing. 
                queens[row] = -1;
                columns.erase(i);
                diagonals1.erase(diagonal1);  
                diagonals2.erase(diagonal2);
            }
        }
    }

    vector<string> generateBoard(vector<int> &queens, int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};

int main()
{
    Solution S1;
    auto result = S1.solveNQueens(4);
}

