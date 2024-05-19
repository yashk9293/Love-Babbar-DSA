// Question Link :- https://leetcode.com/problems/linked-list-cycle-ii/
// Linked List Cycle II

// Leetcode
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // now if the loop is present then slow and fast will intersect
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};