// Question Link :- https://bit.ly/3uaGRRU 
// Remove Duplicates from Un-Sorted Linked List


// Approach - 1
// T.C = O(n^2)
// S.C = O(1)
Node* removeUnsorted(Node* head){
    Node* curr = head;
    while(curr != NULL && curr->next != NULL){
        Node* temp = curr;
        while(temp->next != NULL){
            if(temp->next->data == curr->data){
                Node* next = temp->next;
                temp -> next = temp->next->next;
                delete(next);
            }
            else{
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}



// Approach - 2 ( T.C = O(nlog(n)) , S.C = O(n) )
// Sort the linked list and then remove duplicates
// but problem here is for eg:- 5 4 6 5 5 2 10 6
// correct output should be to 5 4 6 2 10 but this approach will give output as  2 4 5 6 10



// Approach - 3
// T.C = O(n)
// S.C = O(n)
#include<bits/stdc++.h>
Node *removeDuplicates(Node *head) {	
    Node* curr = head;
    Node* prev = NULL;
    unordered_map<int, int> visited;
    
    while(curr != NULL){
        if(!visited[curr->data]){
            visited[curr->data] = 1;
            prev = curr;
            curr = curr -> next;
        }
        else{
            prev -> next = curr -> next;
            delete curr;
        }
        curr = prev -> next;
    }
    return head;
}

// OR
Node* removedulplicate2(Node* head){
    if(head==NULL){
        return NULL;
    }
    map<int , bool> markmap;
    Node* curr = head;
    Node* prev;
    while(curr != NULL){
        if(markmap[curr->data]==false) {
            markmap[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
        else {
            prev->next = curr->next;
            Node* del = curr;
            del->next = NULL;
            delete(del);
            curr = prev->next;
        }
    }
    return head;
}



