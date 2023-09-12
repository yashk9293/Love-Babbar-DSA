// Question Link :- https://www.codingninjas.com/studio/problems/reverse-the-singly-linked-list_799897
// Reverse Linked List


// Iterative Approach (T.C = O(n))
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)  {
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* forward = NULL;

    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}



// Recursive Approach - 1 (T.C = O(n))
void reverse(LinkedListNode<int>* &head, LinkedListNode<int>* curr, LinkedListNode<int>* prev) {
    // base case
    if(curr == NULL) {
        head = prev;
        return;
    }

    LinkedListNode<int>* forward = curr -> next;
    reverse(head, forward, curr);
    curr -> next = prev;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* prev = NULL;
    reverse(head, curr, prev);
    return head;
}




// Recursive Approach - 2 (T.C = O(n))
void reverse1(LinkedListNode<int>* &head, LinkedListNode<int>* curr, LinkedListNode<int>* prev) {
    // base case
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    LinkedListNode<int>* chotaHead = reverse1(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return chotaHead;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    return reverse1(head);
}