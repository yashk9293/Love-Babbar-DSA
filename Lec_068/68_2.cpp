// Question Link :- https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
// Flatten binary tree to linked list

   /*
                   1
                  / \
                 2   5
                / \   \
               3   4   6
   */


// Approach - 1 (using Stack - striver)
// S.C = O(N)
// T.C = O(N)
st.push(root);
while(!st.empty()) {
    curr=s.top();
    st.pop();
    if(curr->right) {
        st.push(curr->right);
    }
    if(curr->left) {
        st.push(curr->left);
    }
    if(!st.empty()) {
        curr->right=st.top();
    }
    curr->left=NULL;
}


// Approach - 2 (using recursion - striver)
// S.C = O(N)
// T.C = O(N)
prev=NULL;
flatten(node){
    if(node==x) {
        return;
    }
    flatten(node->right);
    flatten(node->left);
    node->right=prev;
    node->left=null;
    prev=node;
}



// Approach-3 (Morris Traversal)
class Solution {
    public:
    void flatten(Node *root) {
        Node* curr = root;
        while(curr!= NULL) {
            if(curr->left) {
                Node* pred=curr->left;
                while(pred->right) {
                    pred=pred->right;
                }
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};

