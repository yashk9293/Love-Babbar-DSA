// Question Link :- https://leetcode.com/problems/delete-node-in-a-bst/
// Delete Node in a BST

// Approach - 1 (Recursion)
// T.C = O()
// S.C = O()
class Solution {
public:
    int findmax(TreeNode* root, int currentMax) {
        while (root != NULL) {
            currentMax = max(currentMax, root->val);
            root = root->right;
        }
        return currentMax;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (root->left != NULL && root->right != NULL) {
                // dekho agar dono null nhi hai to left part me se max khojo..uske baad usko replace krdo jo key tha..
                int v = findmax(root->left, INT_MIN);
                root->val = v;   //  replace of key
                // uske baad jisko tm max khoja hai usko remove kr do root->left me se..kyoki wo 2 jagah hai...
                root->left = deleteNode(root->left, v);   
            } else if (root->left != NULL) {
               return root->left;
            } else if (root->right != NULL) {
                return root->right;   
            } else {
                return NULL;
            }
        }
        return root;
    }
};




// Approach - 2
// T.C = O()
// S.C = O()
class Solution {
public:
    void inOrder(vector<int>&ans, TreeNode* root){
        if(root == NULL) {
            return;
        }
        inOrder(ans, root->left);
        ans.push_back(root->val);
        inOrder(ans, root->right);
    }

    TreeNode* makeBST(vector<int>& result, int l, int r) {
        if(l > r) {
            return NULL;
        }
        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(result[mid]);
        node->left = makeBST(result, l, mid-1);
        node->right = makeBST(result, mid+1, r);
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int> ans;
        inOrder(ans, root);

        vector<int> result;
        for(int i=0; i<ans.size(); i++) {
            if(ans[i] != key) {
                result.push_back(ans[i]);
            }
        }
        return makeBST(result, 0, result.size()-1);

    }
};
