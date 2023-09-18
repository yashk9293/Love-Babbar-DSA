// Question Link :- https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
// Check if Linked List is Palindrome

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
    bool isPalindrome(Node *head) {
        vector<int> arr;
        
        Node* temp = head;
        
        while(temp != NULL) {
            arr.push_back(temp -> data);
            temp = temp -> next;
        }
        return checkPalindrome(arr);
    }
};




// Approach - 2
class Solution {
  private:
    Node* getMid(Node* head ) {
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast-> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    Node* reverse(Node* head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        if(head -> next == NULL) {
            return true;
        }
        
        //step 1 -> find Middle
        Node* middle = getMid(head);
        //cout << "Middle " << middle->data << endl;
        
        //step2 -> reverse List after Middle
        Node* temp = middle -> next;
        middle -> next = reverse(temp);
        
        //step3 - Compare both halves
        Node* head1 = head;
        Node* head2 = middle -> next;
        
        while(head2 != NULL) {
            if(head2->data != head1->data) {
                return 0;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    
        //step4 - repeat step 2
        temp = middle -> next;
        middle -> next = reverse(temp);
        
        return true;
    }
};