// Question Link :- https://www.codingninjas.com/studio/problems/reverse-list-in-k-groups_983644
// Reverse List In K Groups

Node* kReverse(Node* head, int k) {
    int size = 0;
    Node* temp = head;

    while(temp!=NULL){
        temp = temp -> next;
        size++;
    }
    if(size < k) return head;   // when number of nodes is not a multiple of k, the left over ones are not to be reversed.

    if(head == NULL) {
        return NULL;
    }

    // step 1: reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count ++;
    }

    // doubly linked list reverse
    // Node* reverseDLL(Node * head) {
    //     Node* curr=head;
    //     Node* pre=NULL;
    //     Node* forward=NULL;
    //     while(curr!=NULL){
    //         forward=curr->next;
    //         curr->prev=curr->next;
    //         curr->next=pre;
    //         pre=curr;
    //         curr=forward;
    //     }
    //     return pre;
    // }

    // step 2: recursion
    if(next != NULL){
        head -> next = kReverse(next, k);
    }

    // step 3: return head 
    return prev;
}