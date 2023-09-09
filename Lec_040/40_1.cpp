// 2nd way of previous problem

class Solution{
    private:
        void solve(int x, int y, string output, vector<string> &ans, vector<vector <int>> visited, vector<vector<int>> m, int n){
            //base conditions
            if(x==n-1 && y==n-1){
                ans.push_back(output);
                return;
            }
            if(x<0 or y < 0 or x>n-1 or y>n-1 or m[x][y] == 0){
                return;
            }
            if(visited[x][y] == 1){
                return;
            }
            if(m[n-1][n-1] == 0){
                return;
            }
            
            //marking
            visited[x][y] = 1;
            
            //down recursive calls
            solve(x+1, y, output + 'D', ans, visited, m, n);
            //left recursive calls
            solve(x, y-1, output + 'L', ans, visited, m, n);
            //right recursive calls
            solve(x, y+1, output + 'R', ans, visited, m, n);
            //up recursive calls
            solve(x-1, y, output + 'U', ans, visited, m, n);
            
            //unmarking
            visited[x][y] = 0;
        }
        
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string output = "";

        vector<vector <int>> visited = m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                visited[i][j] = 0;
            }
        }
        int x=0;
        int y=0;
        solve(x,y,output, ans, visited, m, n);
        return ans;
    }
};