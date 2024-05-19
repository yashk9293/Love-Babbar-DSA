// Question Link :- https://www.geeksforgeeks.org/problems/circular-linked-list/1
// Check If Circular Linked List

// T.C = O(n)
// S.C = O(1)
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

/*
 _________              ________
 |_3_|___|-->       :-->|_3_|___|--:
                    :______________:
not circlular           circlular

*/



// Map Approach
// T.C = O(n)
// S.C = O(n)
bool isCircular(Node *head) {
    if (head == NULL) {
        return true;
    }
    unordered_map<Node *, bool> visited;
    visited[head] = true;
    Node *temp = head->next;

    while (temp != NULL) {
        if (visited[temp]) {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
