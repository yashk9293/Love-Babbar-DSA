// Question Link :- https://leetcode.com/problems/binary-tree-preorder-traversal
// Iterative Preorder Traversal

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root==NULL){
            return preorder;
        }
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            preorder.push_back(root->val);
            if(root->right){
                st.push(root->right);
            }
            if(root->left){
                st.push(root->left);
            }
        }
        return preorder;
    }
};