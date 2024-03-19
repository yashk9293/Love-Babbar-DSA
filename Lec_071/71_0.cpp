// Question Link :- https://www.codingninjas.com/studio/problems/two-sum-in-a-bst_1062631
// Two Sum IV - Input is a BST


// Approach - 1 (Brute Force)
// T.C = O(n^2)
// S.C = O(h)
// travel for every node

// node, target-node => left, right
// node->left, taget-node->left => left, right
// node->right, target-node->right => left, right
// .
// .


// Approach - 2 
// T.C = O(n)
// S.C = O(h)
void inOrder(BinaryTreeNode<int>* root, vector<int>& ans) {
    if(root == NULL) {
        return;
    }
    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    if(root == NULL) {
        return false;
    }
    vector<int> inOrderVal;
    inOrder(root, inOrderVal);

    int i=0, j=inOrderVal.size()-1;
    while(i < j) {
        int sum = inOrderVal[i] + inOrderVal[j];
        if(sum == target) {
            return true;
        }
        if(sum > target) {
            j--;
        } 
        else {
            i++;
        }
    }
    return false;
}