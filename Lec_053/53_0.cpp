// Question Link :- https://www.codingninjas.com/studio/problems/mergesort-linked-list_630514
// MergeSort Linked List

// Approach - 1[Naive]
// T.C = O(n)
// S.C = O(n)

// 1. create an array
// 2. copy all data from linked list to array
// 3. Sort the array
// 4. change thhe data of the linked list while traversing the array

/* Pseudocode

func(head) {
    arr a[];
    temp = head;
    while(temp) {
        arr.add(temp-> data);
        temp = temp->next;
    }
    sort(arr);
    i=0, temp = head;
    while(temp != NULL) {
        temp->data = arr[i];
        temp= temp->next;
        i++;
    }
    return head;
}

*/




// Follow up - If we don't want to change the value of linked list, just change the links OR we want O(1) S.C
// Approach - 2 (Optimal)
// T.C = O(n)
// S.C = O(1) [excluding recursive stack space]
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *findMid(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *left, ListNode *right) {
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }
        ListNode *ans = new ListNode(-1);
        ListNode *temp = ans;

        // merge 2 sorted Linked List
        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        while (left != NULL) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while (right != NULL) {
            temp->next = right;
            temp = right;
            right = right->next;
        }

        ans = ans->next;
        return ans;
    }

    ListNode *mergeSort(ListNode *head) {
        // base case
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // break linked list into 2 halvs, after finding mid
        ListNode *mid = findMid(head);

        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;          // we have to break linked list into two halves

        // recursive calls to sort both halves
        left = mergeSort(left);
        right = mergeSort(right);

        // merge both left and right halves
        ListNode *result = merge(left, right);

        return result;
    }

    ListNode *sortList(ListNode *head) {
        return mergeSort(head);
    }
};

/*

Why is quick sort preferred for arrays and merge sort for linked lists ?
https://www.codingninjas.com/studio/library/why-is-quick-sort-preferred-for-arrays-and-merge-sort-for-linked-lists

*/
