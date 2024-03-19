// Question Link :- https://www.codingninjas.com/studio/problems/preorder-traversal-to-bst_893111
// Preorder traversal of a BST

// Approach - 1
// building bst directly from the given array/vector
// -chota hoga toh left, bada hoga toh right
// problem - hamehsa har iteration root node se start hoga (so T.C = O(n^2))



// Approach - 2
// preorder ko sort karke inorder aa jayega
// then make bst



// Approach - 3 (using min, max value at each node)
BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int maxi, int& i){
    if(i>=preorder.size()) {
        return NULL;
    }

    if(preorder[i] < mini || preorder[i] > maxi) {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i=0;
    return solve(preorder, mini, maxi,i);
}



// using only maxi (not important as time complexity is same)
class Solution {
private:
    TreeNode *getBST(vector<int>& preorder, int maxi,int &i){
        if(i==preorder.size() || preorder[index]>maxi){
            return NULL;
        }
        TreeNode *root=new TreeNode(preorder[i++]);
        
        root->left=getBST(preorder, root->val, i);
        root->right=getBST(preorder, maxi, i);
        
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
      int i=0;
      return getBST(preorder, INT_MAX, i);
        
    }
};






// Approach - 4
class Solution {
public:
    TreeNode* helper(vector<int> &v, int s, int e){
        if(s>e) {
            return nullptr;
        }
        if(s==e){
            TreeNode* node = new TreeNode(v[s]);
            return node;
        }
        TreeNode* root= new TreeNode(v[s]);
        int i=s+1;
        while( i<=e && v[i]<v[s]){
            i++;
        }
        TreeNode* left = helper(v, s+1, i-1);
        TreeNode* right = helper(v, i, e);
        root->left = left;
        root->right = right;

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size()-1);
    }
};