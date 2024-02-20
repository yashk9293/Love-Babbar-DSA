#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeinput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()) {
        Node* FrontNode = Q.front();
        Q.pop();

        if(FrontNode == NULL) {
            cout << endl;
            
            if(!Q.empty()) {
                Q.push(NULL);
            }
        } else {
            cout << FrontNode->data << " ";

            if(FrontNode->left) {
                Q.push(FrontNode->left);
            }

            if(FrontNode->right) {
                Q.push(FrontNode->right);
            }
        }
    }
}

int minVal(Node* root) {
    if(root == NULL) {
        return -1;
    }

    Node* temp = root;
    while(temp->left) {
        temp = temp->left;
    }

    return temp->data;
}

// int maxVal(Node* root) {
//     if(root == NULL) {
//         return -1;
//     }
    
//     Node* temp = root;
//     while(temp->right) {
//         temp = temp->right;
//     }

//     return temp->data;
// }

Node* DeletionInBST(Node* root, int data) {
    if(root == NULL) {
        return root;
    }

    if(root->data == data) {
        
        // 0 Child
        if(root->left==NULL && root->right==NULL) {
            delete root;
            return NULL;
        }

        // 1 Child
        // Left Child
        if(root->left!=NULL && root->right==NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Right Child
        if(root->left==NULL && root->right!=NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 Child
        // min value from right subtree
        if(root->left!=NULL && root->right!=NULL) {
            int mini = minVal(root->right);
            root->data = mini;
            root->right = DeletionInBST(root->right, mini);
            return root;
        }

        // OR
        // max value from left subtree
        // if(root->left!=NULL && root->right!=NULL) {
        //     int mini = maxVal(root->left);
        //     root->data = maxi;
        //     root->left = DeletionInBST(root->left, maxi);
        //     return root;
        // }

    } 
    else if(data > root->data) {
        root->right = DeletionInBST(root->right, data);
        return root;
    } 
    else {
        root->left = DeletionInBST(root->left, data);
        return root;
    }
}

int main() {
    Node* root = NULL;
    int key;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << "Enter the key to delete : ";
    cin >> key;

    cout << endl << "Before Deletion : " << endl;
    levelOrderTraversal(root);
    
    root = DeletionInBST(root, key);

    cout << endl << "After Deletion : " << endl;
    levelOrderTraversal(root);

    return 0;
}



// Input :-
// Enter data to create BST : 50 20 70 10 30 90 110 -1
// Enter the key to delete : 70


//Output :- 
// Before Deletion : 
// 50 
// 20 70 
// 10 30 90 
// 110 

// After Deletion : 
// 50 
// 20 90 
// 10 30 110 