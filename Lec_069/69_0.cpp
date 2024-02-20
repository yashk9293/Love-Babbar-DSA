#include<iostream>
#include<queue>
using namespace std;

// in BST, insertion complexity is O(log n)

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d) {
            this->data = d;
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
    }
    else {
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
        }
        else {
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

void inorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << endl << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);

    cout << "Printing Inorder" << endl;
    inorder(root);

    cout << endl << "Printing Preorder" << endl;
    preorder(root);

    cout << endl << "Printing Postorder" << endl;
    postorder(root);

    return 0;
}


// **************** NOTE **************
// Inorder of BST is always sorted




// Input :-
// Enter data to create BST : 10 8 21 7 27 5 4 3 -1

// Output :-
// Level Order Traversal : 
// 10 
// 8 21 
// 7 27 
// 5 
// 4 
// 3 
// Printing Inorder
// 3 4 5 7 8 10 21 27 
// Printing Preorder
// 10 8 7 5 4 3 21 27 
// Printing Postorder
// 3 4 5 7 8 27 21 10

