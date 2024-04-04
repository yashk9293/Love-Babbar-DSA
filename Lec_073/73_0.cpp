// Question Link :- https://www.codingninjas.com/studio/problems/largest-bst-subtree_893103
// Size of Largest BST in Binary Tree

// Approach - 1 (Brute Force)
// T.C = O(n^2)
// S.C = O(n)
// in every node we will call isValidBST() function which we had done earlier

bool isValidBST(TreeNode* root, int min, int max) {
    if (root == NULL) {
        return true;           // Base case: An empty subtree is a valid BST.
    }
    if (root->data < min || root->data > max) {       // Check if the data of the current node is within the specified range.
        return false;
    }
    return isValidBST(root->left, min, root->data - 1) && isValidBST(root->right, root->data + 1, max);
}

int size(TreeNode* root) {
    if (root == NULL) {    // Base case: Size of an empty subtree is 0.
        return 0;
    }
    return 1 + size(root->left) + size(root->right);        
}

int largestBST(TreeNode* root) {
    if (isValidBST(root, INT_MIN, INT_MAX) == true) {
        return size(root);      // Return the size of the current subtree.
    }
    return max(largestBST(root->left), largestBST(root->right));
}








// Approach - 2 (Optimal Solution)
// T.C = O(n)
// S.C = O(n)

class info {
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};

info solve(TreeNode* root, int &ans) {
    // base case
    if(root == NULL) {
        return {INT_MIN, INT_MAX, true, 0};
    }
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi) && (root->data < right.mini)) {
        currNode.isBST = true;
    } 
    else {
        currNode.isBST = false;
    }

    if(currNode.isBST) {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

int largestBST(TreeNode* root) {
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}