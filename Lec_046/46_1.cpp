// Question Link :- https://leetcode.com/problems/reverse-nodes-in-k-group/
// Reverse Nodes in k-Group

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        
        // reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        ListNode* temp = head;

        int count = 0;
        
        // count remaining nodes
        int countNodes = 0;
        while(temp != NULL){
            countNodes++;
            temp = temp->next;
        }
        
        if(countNodes >= k){
            while(curr != NULL && count < k){
                forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
                count++;
            }
                if(forward != NULL){
                head->next = reverseKGroup(forward, k);
            }
        }
        else{
            return head;
        }
        
        return prev;
    }
};