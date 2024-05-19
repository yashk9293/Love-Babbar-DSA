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




// 1 2 5 4 5 6
// mid is : 5 and 4, but here we have to consider 5 for splitting
// the linked list into two equal halves, isliye line 8 pe fast = head->next liye hai

// warna mid nikalne ke liye slow = head aur fast = head lete hai, in 45_1
// kyuki waha 1 2 5 4 5 6, me mid element 4 ko lete hai
