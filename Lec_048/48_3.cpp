// Question Link :- https://www.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1
// Split a Circular Linked List into two halves

// T.C = O(n)
// S.C = O(1)
void splitList(Node *head, Node **head1_ref, Node **head2_ref) {
    Node* slow=head;
    Node* fast=head->next;
    while(fast != head && fast->next != head) {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    *head1_ref=head;
    *head2_ref = slow->next;
    while(fast->next != head) {
        fast = fast->next;
    }
    fast->next = slow->next;
    slow->next = head;
}
