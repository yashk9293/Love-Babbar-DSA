// Question Link :- https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Remove Duplicates from Sorted List

// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        ListNode* temp = head;
        while(temp && temp->next) {  
            if (temp->val == temp->next->val) {
                ListNode *deleteNode = temp->next;    // is node ko delete karna hai
                temp->next = temp->next->next;
                delete deleteNode;
            } else {
                temp = temp->next;
            }
        }
        return head; 
    }
};
