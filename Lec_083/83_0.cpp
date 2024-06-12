// Question Link :- https://leetcode.com/problems/n-queens/
// N-Queens (Striver)

// Approach - 1
// T.C = O(N! * N)
// S.C = O(N^2)
class Solution {
private:
    bool isSafe(int row, int col, vector<string> &board, int n) {
        // check upper diagonal
        int duprow = row;
        int dupcol = col;

        while(row>=0 && col>=0) {
            if(board[row][col]= 'Q') {
                return false;
                row--;
                col--
            }
        }

        row=duprow;
        col=dupcol;
        while(col>=0) {
            if(board[row][col]='Q') {
                return false;
            }
            col--;
        }

        row=duprow;
        col=dupcol;
        while(row<n && col>=0) {
            if(board[row][col]= 'Q') {
                return false;
                row++;
                col--
            }
        }

        return true;
    }

public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++) {
            if(isSafe(row, column, board, n)) {
                board[row][column]='Q';
                solve(col+1, board, ans, n);
                board[row][column]='.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, ".");
        for(int i=0; i<n; i++) {
            board[i]=s;
        }
        solve(0, board, ans, n);
        return ans;
    }
};




// if the question was
// vector<vector<int>> solveNQueens(int n) 
// then in place of 'Q' we had used 1 and in place of '.' we use 0.