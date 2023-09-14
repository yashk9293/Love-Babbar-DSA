// Question Link :- https://www.codingninjas.com/studio/problems/circularly-linked_1070232
// Circularly Linked

// correct solution but giving TLE in some test cases
bool isCircular(Node* head){
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;
}




// Fastest successfully submitted solution
bool isCircular(Node* head) {
    if(head==NULL) {
        return true;
    }
    Node* prev = head;
    Node* temp = head->next;
    while(temp != NULL && temp!= head) {
        prev->next=NULL;
        prev=temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        return false;
    }
    else {
        return true;;
    }
}




// Map Approach
bool isCircular(Node *head) {
    if (head == NULL) {
        return true;
    }
    unordered_map<Node *, bool> m;
    m[head] = true;
    Node *temp = head->next;

    while (temp != NULL && temp != head) {
        m[temp] = true;
        temp = temp->next;
    }
    if (m[temp]) {
        return true;
    }
    else {
        return false;
    }
}