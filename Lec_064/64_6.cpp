// Question Link :- https://leetcode.com/problems/binary-tree-right-side-view
// Binary Tree Right Side View

// T.C = O(N)
// For a balanced binary tree, the height is log2N but in the worst case when the tree is skewed, the complexity becomes O(N).

// S.C = O(N)
// The size of this result vector is proportional to the height of the Binary Tree which will be log2N when the tree is balanced and O(N) in the worst case of a skewed tree.


// Approach - 1 (Pre Order Traversal)
class Solution {
    public:
    // reversed pre order traversal
    void solve(Node *root, vector<int> &ans, int level) {
        if(root == NULL) {
            return;
        }
        // we entered into a new level
        if(level == ans.size()) {
            ans.push_back(root->data);
        }
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
    }
    
    vector<int> rightView(Node *root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};




// codestorywithMIK
// Approach - 2 (Level Order Traversal)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;   // modification 1
        if(root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            TreeNode *node = NULL;  // modification 2
            for(int i=0; i<size; i++) {
                node = q.front();
                q.pop();
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            ans.push_back(node -> val);  // modification 3
        }
        return ans;
    }
};
