// Question Link :- https://www.geeksforgeeks.org/problems/largest-bst/1
// https://www.codingninjas.com/studio/problems/largest-bst-subtree_893103
// Size of Largest BST in Binary Tree
// (Return the size of the largest sub-tree which is also a BST)

// Brute Force
// T.C = O(n^2)
// S.C = O(n)
// in every node we will call isValidBST() function which we had done earlier

class Solution{
    public:
    bool isValidBST(Node* root, long mini, long maxi) {
        if(root == NULL) {
            return true;
        }
        if(root->data <= mini || root->data >= maxi) {
            return false;
        }
        bool x = isValidBST(root->left, mini, root->data);
        bool y = isValidBST(root->right, root->data, maxi);
        return x && y;
    }
    
    int size(Node* root) {
        if (root == NULL) {    // Base case: Size of an empty subtree is 0.
            return 0;
        }
        return 1 + size(root->left) + size(root->right);        
    }
    
    int largestBst(Node *root) {
    	if (isValidBST(root, LLONG_MIN, LLONG_MAX) == true) {
            return size(root);      // Return the size of the current subtree.
        }
        return max(largestBst(root->left), largestBst(root->right));
    }
};






// Optimal Solution
// T.C = O(n)
// S.C = O(n)
class Result {
public:
    int size, max, min;
    
    Result(int size, int max, int min) {
        this->size = size;
        this->max = max;
        this->min = min;
    }
};

class Solution {
  private:
    Result solve(Node *root) {
        if (root == NULL) {
            return Result(0, INT_MIN, INT_MAX);   // INT_MIN in place of max and INT_MAX in place of min
        }
        Result left = solve(root->left);
        Result right = solve(root->right);
        
        if (root->data > left.max && root->data < right.min) {
            return Result(1 + left.size + right.size, max(root->data, right.max), min(root->data, left.min)); 
        }
        return Result(max(left.size, right.size), INT_MAX, INT_MIN);
    }
    
  public:
    int largestBst(Node *root) {
        return solve(root).size;
    }
};
