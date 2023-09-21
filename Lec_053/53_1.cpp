// Question Link :- https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
// Flattening a Linked List
// Reference - https://youtu.be/ysytSSXpAI0 (Striver)

Node *mergeTwoLists(Node *a, Node *b) {

    Node *temp = new Node(0);
    Node *res = temp;

    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    if(a) {
        temp->bottom = a;
    }
    else {
        temp->bottom = b;
    }

    return res->bottom;
}

Node *flatten(Node *root) {

    if (root == NULL || root->next == NULL)
        return root;

    // recursion for list on right
    root->next = flatten(root->next);

    // now merge
    root = mergeTwoLists(root, root->next);

    // return the root
    // it will be in turn merged with its left
    return root;
}