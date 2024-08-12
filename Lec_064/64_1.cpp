// Question Link :- https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// Tree Boundary Traversal

// T.C = O(N) -> left O(H) + right O(H) + traversal O(N)
// S.C = O(N)
// O(H) or O(log2N) Recursive stack space while traversing the tree. In the worst case scenario the 
// tree is skewed and the auxiliary recursion stack space would be stacked up to the maximum depth 
// of the tree, resulting in an O(N) auxiliary space complexity.

class Solution {
public:
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }
    
    void leftBoundary(Node *root, vector<int>&ans){
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }
        ans.push_back(root->data);
        if (root->left != NULL) {
            leftBoundary(root->left, ans);
        } else {
            leftBoundary(root->right, ans);
        }
    }
    
    void Leafnodes(Node *root, vector<int>&ans) {
        // INORDER TRAVERSAL
        if (root == NULL) {
            return;
        }
        Leafnodes(root->left, ans);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
        }
        Leafnodes(root->right, ans);
    }
    
    void rightBoundary(Node *root, vector<int>& ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }
        if (root->right != NULL) {
            rightBoundary(root->right, ans);
        } else {
            rightBoundary(root->left, ans);
        }
        ans.push_back(root->data);  // add after recursion to reverse the order
    }
    
    vector <int> boundary(Node *root) {
        vector<int> ans;
        if(!isLeaf(root)) {
            ans.push_back(root->data);
        }
        if (root->left != NULL) {
            leftBoundary(root->left, ans);
        }
       //add leaf
        Leafnodes(root, ans); 

        // Add right boundary nodes excluding the root and leaf nodes, in reverse order
        if (root->right != NULL) {
            rightBoundary(root->right, ans);
        }
        
        return ans;
    }
};
