// Question Link :- https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
// Flattening a Linked List 


// Approach - 1 (Brute Force) [Striver]
// T.C = O(N*M) + O(N*M log(N*M)) + O(N*M) where N is the length of the linked list along the 
// next pointer and M is the length of the linked list along the child pointer.
// S.C = O(N*M)
Node* convertArrToLinkedList(vector<int>& arr){
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    for(int i = 0; i < arr.size(); i++){
        temp->child = new Node(arr[i]); 
        temp = temp->child; 
    }
    return dummyNode->child; 
}

Node* flattenLinkedList(Node* head) {
    vector<int> arr;
    while (head != NULL) {
        Node* t2 = head;
        while (t2 != NULL) {
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        head = head->next;
    }
    sort(arr.begin(), arr.end());

    return convertArrToLinkedList(arr);
}








// codestorywithMIK (same code 49_1)
// Approach - 2 (Using Recursion) [Optimal] 
// T.C = O(2 n*m)
// S.C = O(1)
// Recursive Space = O(n*m)
Node* mergeTwoLists(Node* head1, Node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    Node* result;
    if (head1->data < head2->data) {     // Compare the nodes and merge them in sorted order
        result = head1;
        result->bottom = mergeTwoLists(head1->bottom, head2);    // bottom is used as wanted in question
    } else {
        result = head2;
        result->bottom = mergeTwoLists(head1, head2->bottom);    // bottom is used as wanted in question
    }

    return result;
}

Node *flatten(Node *head) {
    if(!head) {
        return head;
    }
    Node* temp = flatten(head->next);
    
    return mergeTwoLists(head, temp);
}
