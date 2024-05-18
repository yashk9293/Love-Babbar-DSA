// Question Link :- https://leetcode.com/problems/merge-two-sorted-lists
// Merge Two Sorted Lists

// codestorywithMIK
// Approach - 1 (Recursive)
//T.C : O(n) - total number of nodes
//S.C : O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* result;
        if(list1->val < list2->val) {
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        } else {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }
        return result;
    }
};




// Love babbar
// Approach - 2 (Iterative)
//T.C : O(n) - total number of nodes
//S.C : O(1)
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if (list1 == NULL) {
            temp->next = list2;
        } else {
            temp->next = list1;
        }
        return ans->next;
    }
};
