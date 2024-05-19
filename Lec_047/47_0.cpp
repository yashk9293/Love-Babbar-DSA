// Question Link :- https://leetcode.com/problems/linked-list-cycle/
// Linked List Cycle


// Using Map
// T.C = O(n)
// S.C = O(n)
bool detectLoop(Node* head) {
    if(head == NULL) {
        return false;
    }
    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL) {
        //cycle is present
        if(visited[temp] == true) {
            cout << "Present on element " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}





// Floyd Detection (slow fast pointer) - preferred
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                return true;
            }
        } 
        return false;
    }
};

// This above code just tells whether the cycle is present or not
