// Question Link :- https://leetcode.com/problems/reverse-linked-list/
// Reverse Linked List

// Iterative Approach (Love Babbar)
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode* curr = head;  
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        while(curr != NULL){  
            forward = curr->next;  
            curr->next = prev;  
            prev = curr;  
            curr = forward; 
        }
        return prev;  
    }
};


// codestorywithMIK
// Recursive Approach - 1 (Preferred)
// T.C = O(n)
// S.C = O(1) (Ignoring recursion stack space)
class Solution {
public:
    ListNode* reverseSolve(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* last   = reverseSolve(head->next);
        head->next->next = head;
        head->next       = NULL;
            
        return last;
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverseSolve(head);
    }
};



// codestorywithMIK
// Recursive Approach - 2
// T.C = O(n)
// S.C = O(1) (Ignoring recursion stack space)
class Solution {
public:
    ListNode* reverseHelp(ListNode* head, ListNode* prev) {
        if(!head) {
            return prev;
        }
        ListNode* temp = head->next;
        head->next = prev;
        
        return reverseHelp(temp, head);
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverseHelp(head, NULL);
    }
};
