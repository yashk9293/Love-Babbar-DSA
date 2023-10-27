// Question Link :- https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
// Height of Binary Tree

// T.C = O(N)
// S.C = O(height)
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        if(node == NULL) {
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
        
        int ans = max(left, right) + 1;
        
        return ans;
    }
};