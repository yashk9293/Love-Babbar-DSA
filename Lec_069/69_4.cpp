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

int maxVal(Node* root) {
    if(root == NULL) {
        return -1;
    }
    
    Node* temp = root;
    while(temp->right) {
        temp = temp->right;
    }

    return temp->data;
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << endl << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);

    cout << endl << "Minimum Value : " << minVal(root);
    cout << endl << "Maximum Value : " << maxVal(root);

    return 0;
}



// Input :-
//Enter data to create BST : 10 8 21 7 27 5 4 3 -1

// Output :-
// Level Order Traversal : 
// 10 
// 8 21 
// 7 27 
// 5 
// 4 
// 3 

// Minimum Value : 3
// Maximum Value : 27