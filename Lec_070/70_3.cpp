// Question Link :- https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
// Predecessor and Successor

// Approach - 1
// T.C = O(n)
// S.C = O(n)
// inorder Traversal, store elements in the vector/array
// find the key in the array, and then successor and predecessor of the key.


// Approach - 2 (Using 2 loop)
// T.C = O(H)
// S.C = O(1)
class Solution {
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        Node* temp = root;   // Initializing temporary node with head.
        while(temp != NULL) {
            if(temp->key <= key) {
                temp = temp->right;
            } else {
                suc = temp;
                temp = temp->left;
            }
        }
        while(root != NULL) {
            if(root->key >= key) {
                root = root->left;
            } else {
                pre = root;
                root = root->right;
            }
        }
    }
};




// Approach - 3 (using 1 loop)
// T.C = O(H)
// S.C = O(1)
class Solution {
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        while(root != NULL) {
            if(key > root->key) {
                pre = root;
                root = root->right;
            } else if(key < root->key) {
                suc = root;
                root = root->left;
            } else {  // Key matches the root's key
                // Find predecessor: Max value in the left subtree
                if(root->left != NULL) {
                    Node* temp = root->left;
                    while(temp->right != NULL) {
                        temp = temp->right;
                    }
                    pre = temp;
                }
                // Find successor: Min value in the right subtree
                if(root->right != NULL) {
                    Node* temp = root->right;
                    while(temp->left != NULL) {
                        temp = temp->left;
                    }
                    suc = temp;
                }
                break;
            }
        }
    }
};





// Approach - 4 (using Recursion)
// T.C = O(H)
// S.C = O(1)
class Solution {
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        if(!root) {
            return;
        }
        if(root->key > key) {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        } else if(root->key < key) {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        } else {
            findPreSuc(root->left, pre, suc, key);
            findPreSuc(root->right, pre, suc, key);
        }
    }
};
