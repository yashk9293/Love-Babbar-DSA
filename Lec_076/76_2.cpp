// Question Link :- https://leetcode.com/problems/merge-k-sorted-lists/
// Merge k Sorted Lists

// Approach - 1 (Naive Approach)
// T.C = O(N*K log(N*K))
// S.C = O(N*K)     Where 'N' is the total number of Nodes

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) {
            return NULL;
        }
        vector<int> ans;

        // Insert nodes in a ans array.
        for (int i = 0; i < k; i++) {
            ListNode* temp = lists[i];
            while (temp != NULL) {
                ans.push_back(temp->val);
                temp =  temp->next;
            }
        }
        // Sort the array.
        sort(ans.begin(), ans.end());

        ListNode *head = NULL, *tail = NULL;

        // Convert into a linked list.
        for (int i = 0; i < ans.size(); i++) {
            ListNode *curr = new ListNode(ans[i]);
            if (head == NULL) {
                head = curr;
                tail = curr;
            } else {
                tail->next = curr;
                tail = curr;
            }
        }
        return head;
    }
};






// codestorywithMIK
// Approach - 2 (Better Approach)
// Divide and Conquer using merging two sorted list
// T.C = O((N*K) log(K)) - There are log(K) levels because in each level the ‘K’ arrays are divided into half.
// S.C = O(log(K)) - for merging 2 sorted list we are using recursive way, so O(log(K))... if iterative way is done then O(1) will be S.C


class Solution {
public:
    ListNode* mergeTwoSortedLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* result;
        if(list1->val < list2->val) {
            result = list1;
            result->next = mergeTwoSortedLists(list1->next, list2);
        } else {
            result = list2;
            result->next = mergeTwoSortedLists(list1, list2->next);
        }
        return result;
    }
    
    ListNode* partitionAndMerge(vector<ListNode*>& lists, int start, int end) {
        if(start == end) {
            return lists[start];
        }
        if(start > end) {
            return NULL;
        }
        int mid = start + (end-start)/2;
        ListNode* l1 = partitionAndMerge(lists, start, mid);
        ListNode* l2 = partitionAndMerge(lists, mid+1, end);
        
        return mergeTwoSortedLists(l1, l2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) {
            return NULL;
        }
        return partitionAndMerge(lists, 0, k-1);
    }
};








// Approach - 3 (Optimal Solution) Using Heap
// T.C = O(N * logK)
// S.C = O(K)

class Solution {
public:
    class compare {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        int k = lists.size();
        if(k == 0) {    // Empty list
            return NULL;
        }
        for(int i=0; i<k; i++) {    // pushing nodes into minHeap
            if(lists[i] != NULL) {
                minHeap.push(lists[i]);
            }
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;

        // comparing next nodes
        while(minHeap.size() > 0) {
            ListNode* curr = minHeap.top();
            minHeap.pop();
            if(curr->next) {
                minHeap.push(curr->next);
            }

            if(head == NULL) {
                head = curr;
                tail = curr;
            } else {
                tail->next = curr;
                tail = curr;
            }
        }
        return head;
    }
};
