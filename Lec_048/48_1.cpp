// Question Link :- https://www.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
// Remove duplicates from an unsorted linked list

// Approach - 1
// T.C = O(n^2)
// S.C = O(1)
Node* removeDuplicates(Node* head){
    Node* curr = head;
    while(curr != NULL && curr->next != NULL){           // i -> 1 to n
        Node* temp = curr;                               //    j -> i to n
        while(temp->next != NULL){                       //       if(i-> data == j-> data) {
            if(curr->data == temp->next->data){          //          delete j
                Node* next = temp->next;                 //       }
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
class Solution {
public:
    Node* removeDuplicates(Node* head){
        if(head==NULL){
            return NULL;
        }
        Node* curr = head;
        Node* prev  = NULL;
        map<int , bool> visited;

        while(curr != NULL){
            if(!visited[curr->data]) {
                visited[curr->data] = true;
                prev = curr;
                curr = curr->next;
            } else {
                prev->next = curr->next;
                Node* del = curr;
                curr->next = NULL;
                delete(del);
                curr = prev->next;
            }
        }
        return head;
    }
};
