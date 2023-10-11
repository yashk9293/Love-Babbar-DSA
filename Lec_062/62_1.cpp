// Level Order Traversal

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

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else {
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }
            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}

int main() {
    node* root = NULL;
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    cout << "\nPrinting the level order traversal output " << endl;
    levelOrderTraversal(root);

    return 0;
}



/*

                     1
                   /   \
                  /     \
                 3       5
                / \     / \
               /   \   /   \
              7    11 17   NULL



Output :-

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

Printing the level order traversal output
1
3 5
7 11 17





*/