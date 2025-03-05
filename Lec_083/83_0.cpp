// Question Link :- https://leetcode.com/problems/n-queens/
// N-Queens


// T.C = O(N! * N)
// The first queen has n choices.
// The second queen has at most (n-1) choices.
// The third queen has at most (n-2) choices, and so on.

// ..And additional O(N) factor due to safety checks

// S.C = O(N^2)
class Solution {
public:
    bool isSafe(int row, int col, vector<string> &grid, int n) {
        // check left row
        for(int i=0; i<col; i++){
            if(grid[row][i] == 'Q'){
                return false;
            }
        }
        // check upper left diagonal
        int i = row;
        int j = col;

        while(i>=0 && j>=0) {
            if(grid[i][j]  == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        // check lower left diagonal
        i = row;
        j = col;
        while(i<n && j>=0) {
            if(grid[i][j] == 'Q') {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    void solve(int col, vector<string> &grid, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(grid);
            return;
        }

        for(int row=0; row<n; row++) {
            if(isSafe(row, col, grid, n)) {
                grid[row][col]='Q';
                solve(col+1, grid, ans, n);
                grid[row][col]='.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.')); // here it will be '.' not "." because the second parameter of the std::string constructor expects a char
        solve(0, board, ans, n);
        return ans;
    }
};




// if the question was
// vector<vector<int>> solveNQueens(int n) 
// then in place of 'Q' we had used 1 and in place of '.' we use 0.
