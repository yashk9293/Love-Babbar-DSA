// Question Link :- https://leetcode.com/problems/merge-two-sorted-lists
// Merge Two Sorted Lists

// APproach - 1 (Runtime - 0ms)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(0); // Dummy node
    ListNode* current = dummy;
    ListNode* p1 = list1;
    ListNode* p2 = list2;

    while (p1 != nullptr && p2 != nullptr) {
        if (p1->val <= p2->val) {
            current->next = p1;
            p1 = p1->next;
        } else {
            current->next = p2;
            p2 = p2->next;
        }
        current = current->next;
    }

    if (p1 != nullptr) {
        current->next = p1;
    }

    if (p2 != nullptr) {
        current->next = p2;
    }

    ListNode* mergedList = dummy->next;
    delete dummy; // Free the dummy node
    return mergedList;
    }
};







// Approach - 2 (Runtime - 8ms)
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    ListNode *ans = new ListNode(-1);
    ListNode *temp = ans;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    while (list1) {
        temp->next = list1;
        temp = list1;
        list1 = list1->next;
    }
    while (list2) {
        temp->next = list2;
        temp = list2;
        list2 = list2->next;
    }

    return ans->next;
}