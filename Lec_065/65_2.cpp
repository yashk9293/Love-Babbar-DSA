// Question Link :- https://practice.geeksforgeeks.org/problems/k-sum-paths/1
// K Sum Paths

// T.C = O(n^2)
// S.C = O(height)
class Solution{
  public:
    void solve(Node* root, int k, int &count, vector<int> path) {
        if(root == NULL) {
            return ;
        }
        path.push_back(root->data);
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);

        //check for K Sum
        int size = path.size();
        int sum = 0;
        for(int i = size-1; i>=0; i--) {
            sum += path[i];
            if(sum == k) {
                count++;
            }
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
    void solve(Node *root,int k,map<int,int>& mp,int &count,int &sum){
        if (root == NULL) {
            return ;
        }
        sum += root->data;
        if (mp.find(sum-k) != mp.end()) {
            count += mp[sum-k];
        }
        mp[sum]++;
        solve(root->left, k, mp, count, sum);
        solve(root->right, k, mp, count, sum);
        mp[sum]--;
        sum -= root->data;
    }

    int sumK(Node *root,int k) { 
        int count = 0;
        map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        solve(root, k, mp, count, sum);
        return count;
    }
};
