// Question Link :- https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Flatten a Multilevel Doubly Linked List

// Leetcode
// Approach - 1 (Iterative)
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
	    while(temp) {
		    if (temp->child) {
			    Node* next = temp->next;
			    temp->next = temp->child;
			    temp->next->prev = temp;
			    temp->child = NULL;
			    Node* p = temp->next;
			    while (p->next) {
                    p = p->next;
                }
			    p->next = next;
			    if(next) {
                    next->prev = p;
                }
		    }
            temp = temp -> next;
	    }
	    return head;
    }
};







// Leetcode
// Approach - 2 (Recursive)
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    Node* flatten(Node* head) {
        Node *temp = head;
        while(temp){
            if(temp->child){
                Node *nxt = temp -> next;
                temp->next = flatten(temp->child);
                temp->child = NULL;
                temp->next->prev = temp;
                while(temp->next){
                    temp = temp->next;    
                }
                temp->next = nxt;
                if(nxt) {
                    nxt->prev = temp;
                }
            } 
            temp = temp->next;
        }
        return head;
    }
};