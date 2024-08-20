// Question Link :- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
// Construct Binary Tree from Preorder and Inorder Traversal (MIK)

// Approach 1
// T.C = O(n^2)
// S.C = O(n)
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        // Base case
        if (start > end) {
            return NULL;
        }
        int rootVal = preorder[idx];
        int i = -1;
        for (int j = start; j <= end; j++) {
            if (inorder[j] == rootVal) {
                i = j;
                break;  // We found the root in inorder
            }
        }
        idx++;  // Move to the next element in preorder

        TreeNode* root = new TreeNode(rootVal);  // Create the root node
        root->left = solve(preorder, inorder, start, i - 1, idx);  // Build left subtree
        root->right = solve(preorder, inorder, i + 1, end, idx);  // Build right subtree
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;  // Start with the first element in preorder
        int n = inorder.size();
        return solve(preorder, inorder, 0, n - 1, idx);
    }
};




// Approach 2 (Using Map)
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    unordered_map<int, int> mpp;  // {node value, index}
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        // NOTE :- idx is taken by reference because it is changing in the function
        if (start > end) {
            return NULL;
        }
        int rootVal = preorder[idx];
        int i = mpp[rootVal];
        idx++;   // Move to the next element in preorder
        
        TreeNode* root = new TreeNode(rootVal);   // Create the root node
        root->left = solve(preorder, inorder, start, i-1, idx);  // Build left subtree
        root->right = solve(preorder, inorder, i+1, end, idx);  // Build right subtree
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;   // Start with the first element in preorder
        mpp.clear();
        int n = preorder.size();
        for(int i = 0; i<n; i++) {
            mpp[inorder[i]] = i;
        }
        return solve(preorder, inorder, 0, n-1, idx);
    }
};
