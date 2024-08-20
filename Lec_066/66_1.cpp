// Question Link :- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
// Construct Binary Tree from Inorder and Postorder Traversal

// Approach 1
// T.C = O(n^2)
// S.C = O(n)
class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start, int end, int &idx) {
        if(start > end) {
            return NULL;
        }
        int rootVal = postorder[idx]; // root nikal gya
        int i = -1;
        for(int j=start; j<=end; j++) {
            if(inorder[j] == rootVal) {
                i = j;
                break;
            }
        }
        idx--;
        TreeNode* root = new TreeNode(rootVal); 
        //why right before left?
        //Postorder traversal processes the right subtree before the left subtree because when you're constructing the tree backwards (from the end of the postorder array), the right subtree comes before the left subtree in the postorder list.
        root->right=solve(inorder, postorder, i+1, end, idx);
        root->left=solve(inorder, postorder, start, i-1, idx);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n-1;
        return solve(inorder, postorder, 0, n-1, idx);
    }
};




// Approach 2 (Using Map)
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    unordered_map<int, int> mpp;  // {node value, index}
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start, int end, int &idx) {
        if(start > end) {
            return NULL;
        }
        int rootVal = postorder[idx]; // root nikal gya
        int i = mpp[rootVal];
        idx--;
        TreeNode* root = new TreeNode(rootVal); 
        //why right before left?
        //Postorder traversal processes the right subtree before the left subtree because when you're constructing the tree backwards (from the end of the postorder array), the right subtree comes before the left subtree in the postorder list.
        root->right = solve(inorder, postorder, i+1, end, idx);
        root->left = solve(inorder, postorder, start, i-1, idx);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        mpp.clear();
        int n = inorder.size();
        int idx = n-1;
        for(int i = 0; i<n; i++) {
            mpp[inorder[i]] = i;
        }
        return solve(inorder, postorder, 0, n-1, idx);
    }
};
