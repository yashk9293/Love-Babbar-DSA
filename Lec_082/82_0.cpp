// Question Link :- https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// Rat in a Maze Problem - I

// T.C = 4^(n x m)
// S.C = O(m x n)

// Solution - 1
class Solution{
    bool isSafe(int new_x, int new_y, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited) {
        if( ((new_x >= 0 && new_x < n) && (new_y >= 0 && new_y < n)) && (arr[new_x][new_y] == 1) && (visited[new_x][new_y] == 0)) {
            return true;
        }
        return false;
    }
    void solve(int x, int y, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited, string path, vector<string> &ans) {
        // base case
        if(x == n-1 && y == n-1) {
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        // Down
        if(isSafe(x+1, y, arr, n, visited)) {
            solve(x+1, y, arr, n, visited, path + 'D', ans);
        }
        
        // Left
        if(isSafe(x, y-1, arr, n, visited)) {
            solve(x, y-1, arr, n, visited, path + 'L', ans);
        }
        
        // Right
        if(isSafe(x, y+1, arr, n, visited)) {
            solve(x, y+1, arr, n, visited, path + 'R', ans);
        }
        
        // Up
        if(isSafe(x-1, y, arr, n, visited)) {
            solve(x-1, y, arr, n, visited, path + 'U', ans);
        }
        visited[x][y] = 0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool> (n,0));
        string path = "";
        
        // EDGE CASE
        if(m[0][0] == 1) {
            solve(0, 0, m, n, visited, path, ans);
        }
        return ans;
    }
};







// Solution - 2
class Solution{
    bool isSafe(int new_x, int new_y, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited) {
        if( ((new_x >= 0 && new_x < n) && (new_y >= 0 && new_y < n)) && (arr[new_x][new_y] == 1) && (visited[new_x][new_y] != 1)) {
            return true;
        }
        return false;
    }
    void solve(int x, int y, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited, string path, vector<string> &ans) {
        // base case
        if(x == n-1 && y == n-1) {
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        int newx[4] = {x+1, x, x, x-1};
        int newy[4] = {y, y-1, y+1, y};
        string movement = "DLRU";
        
        for(int i = 0; i < 4; i++) {
            if(isSafe(newx[i], newy[i], arr, n, visited)) {
                solve(newx[i], newy[i], arr, n, visited, path + movement[i], ans);
            }
        }
        visited[x][y] = 0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool> (n,0));
        string path = "";
        
        // EDGE CASE
        if(m[0][0] == 1) {
            solve(0, 0, m, n, visited, path, ans);
        }
        return ans;
    }
};