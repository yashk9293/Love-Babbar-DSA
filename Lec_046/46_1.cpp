// Question Link :- https://leetcode.com/problems/reverse-nodes-in-k-group
// Reverse Nodes in k-Group

// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) {
            return NULL;
        }
        int size = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            size++;
        }
        if(size < k) {  // if size of remaining nodes is less than k then the left over are not to be reversed
            return head;
        }
        // reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        int count = 0;
  
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
        return prev;
    }
};
