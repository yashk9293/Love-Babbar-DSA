// Question Link :- https://leetcode.com/problems/palindrome-linked-list/
// Palindrome Linked List

/* Approach - 1
1. create an array
2. copy linked list content into array - O(n)
3. write logic to check palindrome or not - O(n/2)

T.C = O(n) + O(n/2) = O(n)
S.C = O(n)
*/

#include<vector>

class Solution{
    private:
    bool checkPalindrome(vector<int> arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        while(s <= e) {
            if(arr[s] != arr[e]) {
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }

    public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(ListNode *head) {
        vector<int> arr;
        
        ListNode* temp = head;
        
        while(temp != NULL) {
            arr.push_back(temp -> val);
            temp = temp -> next;
        }
        return checkPalindrome(arr);
    }
};






// Approach - 2 (Reversing the 2nd half of linked list)
// T.C = O(n)
// S.C = O(1)
class Solution {
  private:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;            // starting node of reversed linked list
    }

    public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(ListNode *head) {
        if(head == NULL || head -> next == NULL) {
            return true;
        }
        
        //step 1 -> find Middle
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != NULL && fast-> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        //step2 -> reverse List after Middle
        ListNode* temp = slow -> next;
        slow -> next = reverseList(temp);
        
        //step3 - Compare both halves of the linked list
        ListNode* head1 = head;
        ListNode* head2 = slow ->next;
        
        while(head1 != NULL && head2 != NULL) {
            if(head1->val != head2->val) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
    
        //step4 - repeat step 2 (to avoid any changes to original linked list)
        temp = slow -> next;
        slow -> next = reverseList(temp);
        
        return true;
    }
};











// Approach - 3 (Follow Up Question)
// T.C = O(n)
// S.C = O(1) auxiliary space
class Solution {
public:
    ListNode* curr;
    bool solve(ListNode* head) {
        if(head == NULL) {
            return true;
        }
        bool ans = solve(head->next);
        if(curr->val != head->val) {
            return false;
        }
        curr = curr->next;
        return ans;
    }
    bool isPalindrome(ListNode* head) {
        curr = head;
        return solve(head);
    }
};
