// Question Link :- https://bit.ly/3rjMQC5
// Remove duplicates from a sorted Doubly Linked List

// (same code as 48_0)
// T.C = O(n)
// S.C = O(1)
#include<bits/stdc++.h>
Node * removeDuplicates(Node *head) {
    if(head == NULL) {
        return NULL;
    }
    Node* temp = head;
    while(temp && temp->next) {  
        if (temp->data == temp->next->data) {
            Node *deleteNode = temp->next;    // is node ko delete karna hai
            temp->next = temp->next->next;
            delete deleteNode;
        } else {
            temp = temp->next;
        }
    }
    return head; 
}
