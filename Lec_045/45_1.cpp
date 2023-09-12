// Question Link :- https://www.codingninjas.com/studio/problems/middle-of-linked-list_973250
// Middle Of Linked List


// Approach - 1
int getLength(Node *head) {
    int len=0;
    while(head != NULL) {
        len++;
        head = head -> next;
    }
    return len;
}

Node *findMiddle(Node *head) {
    int len = getLength(head);
    int ans = (len/2);

    Node *temp = head;
    int cnt = 0;
    while(cnt < ans) {
        temp = temp -> next;
        cnt++;
    }
    return temp;
}







// Approach - 2
Node *getMiddle(Node* head) {
    // 1 node or null node
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    //2 nodes
    if(head -> next -> next == NULL) {
        return head -> next;
    }

    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;
}

Node *findMiddle(Node *head) {
    return getMiddle(head);
}