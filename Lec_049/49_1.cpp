// Question Link :- https://www.codingninjas.com/studio/problems/merge-two-sorted-linked-lists_800332
// Merge Two Sorted Linked Lists

// Recursive Approach
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    // Write your code here.
    if(first==NULL)
        return second;
    if(second==NULL){
        return first;
    }
    if(first->data < second->data) {
        first->next = sortTwoLists(first->next, second);
        return first;
    }
    else {
        second->next = sortTwoLists(first, second->next);
        return second;
    }
}





// Love Babbar approach (giving TLE)
Node<int>* solve(Node<int>* first, Node<int>* second) {
    
    // if only 1 element is present in the first list
    if(first -> next == NULL) {
        first -> next = second;
        return first;
    }
    
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1 -> next;
    
    Node<int>* curr2 = second;
    Node<int>* next2 = curr2 -> next;
    
    while(next1 != NULL && curr2 != NULL) {
        
        if( (curr2 -> data >= curr1 -> data ) 
           && ( curr2 -> data <= next1 -> data)) {
            
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else {
            curr1 = next1;
            next1 = next1 -> next;

            if(next1 == NULL) {
                curr1 -> next = curr2;
                return first;
            }
        }
    }
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
    
    if(first -> data <= second -> data ){
        return solve(first, second);
    }
    else {
        return solve(second, first);
    }
}