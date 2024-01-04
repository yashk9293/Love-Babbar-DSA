// Question Link :- https://practice.geeksforgeeks.org/problems/k-sum-paths/1
// K Sum Paths

// T.C = O(n^2)     Giving Runtime error
// S.C = O(height)
class Solution{
  public:
    void solve(Node* root, int k, int &count, vector<int> path) {
        //base case
        if(root == NULL)
            return ;
        
        path.push_back(root->data);
        
        //left
        solve(root->left, k, count, path);
        //right
        solve(root->right, k, count, path);
        
        //check for K Sum
        int size = path.size();
        int sum = 0;
        for(int i = size-1; i>=0; i--)  {
            sum += path[i];
            if(sum == k)
                count++;
        }
        
        path.pop_back();
    }
    int sumK(Node *root,int k) {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};





// T.C = O(n) 
// S.C = O(height)
class Solution{
  public:
    int solve(Node *root, int k, map<int,int> &s, int sum) {
        if(root == NULL)
            return 0;
        int c = 0;
        sum += root -> data;
        if(s.find(sum-k) != s.end())
            c += s[sum - k];
        s[sum]++;
        int left = solve(root -> left, k, s, sum);
        int right = solve(root -> right, k, s, sum);
        s[sum]--;
        return c + left + right;
    }
    int sumK(Node *root,int k)
    {
        // code here
        map<int,int> s;
        s[0]++;
        return solve(root, k, s, 0);
    }
};