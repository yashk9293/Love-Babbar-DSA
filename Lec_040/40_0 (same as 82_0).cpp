// Question Link :- https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// Rat in a Maze Problem - I

// T.C = 4^(n x m)
// S.C = O(m x n)

// Approach 1 : Passing path as reference
class Solution {
  public:
    void solve(int i, int j, int n, vector<vector<int>> &mat, vector<vector<bool>>& visited, string& path, vector<string>& ans) {
        if(i == n-1 && j == n-1) {
            ans.push_back(path);
            return;
        }
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || mat[i][j] == 0) {
            return;
        }
        
        visited[i][j] = true;

        // Move Down
        path.push_back('D');
        solve(i + 1, j, n, mat, visited, path, ans);
        path.pop_back(); // Backtrack
        
        // Move Left
        path.push_back('L');
        solve(i, j - 1, n, mat, visited, path, ans);
        path.pop_back(); // Backtrack

        // Move Right
        path.push_back('R');
        solve(i, j + 1, n, mat, visited, path, ans);
        path.pop_back(); // Backtrack

        // Move Up
        path.push_back('U');
        solve(i - 1, j, n, mat, visited, path, ans);
        path.pop_back(); // Backtrack

        visited[i][j] = false;
    }

    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> ans;
        string path;
        vector<vector<bool>> visited(n, vector<bool> (n, 0));
        
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
            return {};
        }

        solve(0, 0, n, mat, visited, path, ans);
        
        return ans;
    }
};







// Approach 2 : Passing path as value, it store copies of itself in each recursive call
class Solution {
  public:
    vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    void solve(int i, int j, int n, vector<vector<int>> &mat, vector<vector<bool>>& visited, string path, vector<string>& ans) {
        if(i == n-1 && j == n-1) {
            ans.push_back(path);
            return;
        }
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || mat[i][j] == 0) {
            return;
        }
        
        visited[i][j] = true;

        solve(i + 1, j, n, mat, visited, path + 'D', ans);
        solve(i, j - 1, n, mat, visited, path + 'L', ans);
        solve(i, j + 1, n, mat, visited, path + 'R', ans);
        solve(i - 1, j, n, mat, visited, path + 'U', ans);

        visited[i][j] = false;
    }

    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> ans;
        string path;
        vector<vector<bool>> visited(n, vector<bool> (n, 0));
        
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
            return {};
        }

        solve(0, 0, n, mat, visited, path, ans);
        
        return ans;
    }
};
