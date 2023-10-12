// InOrder PreOrder PostOrder Traversal

#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void inorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);
}

void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";
}

int main() {
    node* root = NULL;
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    cout << "\ninorder traversal is:  ";
    inorder(root); 

    cout << endl << "preorder traversal is:  ";
    preorder(root); 

    cout << endl << "postorder traversal is:  ";
    postorder(root); 


    return 0;
}




/*

Enter the data: 
1
Enter data for inserting in left of 1
Enter the data: 
3
Enter data for inserting in left of 3
Enter the data: 
7
Enter data for inserting in left of 7
Enter the data: 
-1
Enter data for inserting in right of 7
Enter the data: 
-1
Enter data for inserting in right of 3
Enter the data: 
11
Enter data for inserting in left of 11
Enter the data:
-1
Enter data for inserting in right of 11
Enter the data:
-1
Enter data for inserting in right of 1
Enter the data:
5
Enter data for inserting in left of 5
Enter the data:
17
Enter data for inserting in left of 17
Enter the data:
-1
Enter data for inserting in right of 17
Enter the data:
-1
Enter data for inserting in right of 5
Enter the data:
-1

inorder traversal is:  7 3 11 1 17 5
preorder traversal is:  1 3 7 11 5 17
postorder traversal is:  7 11 3 17 5 1


*/