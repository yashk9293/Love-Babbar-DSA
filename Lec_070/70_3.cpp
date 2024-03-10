// Question Link :- https://www.codingninjas.com/studio/problems/_893049?topList=love-babbar-dsa-sheet-problems
// Predecessor And Successor In BST

// Approach - 1
// T.C = O(n)
// S.C = O(n)
// inorder Traversal, store elements in the vector/array
// find the key in the array, and then successor and predecessor of the key.


// Approach - 2
// T.C = O(n)
// S.C = O(1)
pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    int predecessor = -1;
    int successor = -1;

    // Initializing temporary node with head.
    TreeNode *temp = root;

    // Traversing in tree.
    while (temp != NULL) {
        if (key > temp->data) {
            // Updating predecessor.
            predecessor = temp->data;
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }

    temp = root;

    // Traversing in tree.
    while (temp != NULL) {
        if (key >= temp->data) {
            temp = temp->right;
        }
        else {
            // Updating successor.
            successor = temp->data;
            temp = temp->left;
        }
    }
    return make_pair(predecessor, successor);
}







// Alternate sol(Love babbar - not necessary) 
// only 2 test case pass, rest giving runtime error

pair<int, int> predecessorSuccessor(TreeNode* root, int key) {
    TreeNode* temp = root;
    int pred = -1;
    int succ = -1;
    
    while(temp->data != key) {
        if(temp->data > key) {
            succ = temp->data;
            temp = temp->left;
        } else {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // Prdecessor
    TreeNode* leftTree = temp->left;
    while(leftTree != NULL) {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // Successor
    TreeNode* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}70