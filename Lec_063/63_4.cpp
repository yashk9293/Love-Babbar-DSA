// Question Link :- https://practice.geeksforgeeks.org/problems/sum-tree/1
// Sum Tree

// T.C = O(N)
// S.C = O(height of tree)
class Solution {
  private:
    
  public:
    int solve(Node* root, bool& res){
        if(!root) {
            return 0;
        }
        int leftSum = solve(root->left, res);
        int rightSum = solve(root->right, res);
        if(!root->left && !root->right) {
            return root->data;
        }
        if(root->data != leftSum + rightSum) {
            return res = false;
        }
        return root->data + leftSum + rightSum;
    }
    
    bool isSumTree(Node* root) {
        bool res = true;
        solve(root, res);
        return res;
    }
};
