// Question Link :- https://www.codingninjas.com/studio/problems/lca-in-a-bst_981280
// LCA of Two Nodes In A BST

// Approach - 1 (Recursive)
// T.C = O(n)
// S.C = O(1)
Node* LCAinBST(Node* root, Node* P, Node* Q) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data < P->data && root->data < Q->data) {
        LCAinBST(root->right, P, Q);
    }
    if(root->data > P->data && root->data > Q->data) {
        LCAinBST(root->left, P, Q);
    }

    return root;
}


// Approach - 2 (Iterative)
// T.C = O(n)
// S.C = O(1)
Node* LCAinBST(Node* root, Node* P, Node* Q) {
    while(root != NULL) {
        if(root->data < P->data && root->data < Q->data) {
            root = root->right;
        } 
        else if (root->data > P->data && root->data > Q->data) {
            root = root->left;
        } 
        else {
            return root;
        }
    }
}