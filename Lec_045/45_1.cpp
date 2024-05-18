// Question Link :- https://leetcode.com/problems/middle-of-the-linked-list/description/
// Middle of the Linked List

// Love babbar
// Approach - 1
//T.C : O(2n)
//S.C : O(1)
int getLength(Node *head) {
    int len=0;
    while(head != NULL) {
        len++;
        head = head -> next;
    }
    return len;
}
Node *findMiddle(Node *head) {
    int len = getLength(head);
    int ans = (len/2);

    Node *temp = head;
    int cnt = 0;
    while(cnt < ans) {
        temp = temp -> next;
        cnt++;
    }
    return temp;
}





// codestorywithMIK
// Approach - 2 (preferred)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow  = head;
        ListNode* fast = head;
        
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        } 
        return slow;
    }
};
