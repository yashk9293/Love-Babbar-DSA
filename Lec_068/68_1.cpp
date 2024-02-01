// T.C = O(N)
// S.C = O(1)


// Morris Traversal for inorder
vector<int> getInorder(TreeNode* root) {
    vector<int> inorder;
    TreeNode *curr=root;
    while(curr != NULL) {
        if(curr -> left == NULL) {
            inorder.push_back(curr->val);
            curr=curr->right;
        }
        else {
            TreeNode *prev = curr->left;
            while(prev->right && prev->right != curr) {
                prev = prev->right;
            }
            if(prev->right == NULL) {
                prev->right = curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                inorder.push_back(curr->val);
                curr=curr->right;
            }
        }
        return inorder;
    }
}






// Morris Traversal for preorder
vector<int> getInorder(TreeNode* root) {
    vector<int> preorder;
    TreeNode *curr=root;
    while(curr != NULL) {
        if(curr -> left == NULL) {
            inorder.push_back(curr->val);
            curr=curr->right;
        }
        else {
            TreeNode *prev = curr->left;
            while(prev->right && prev->right != curr) {
                prev = prev->right;
            }
            if(prev->right == NULL) {
                prev->right = curr;
                preorder.push_back(curr->val);   // 1 line change from inorder
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                curr=curr->right;
            }
        }
        return preorder;
    }
}