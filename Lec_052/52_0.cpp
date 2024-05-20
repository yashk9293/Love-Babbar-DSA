// Question Link :- https://leetcode.com/problems/copy-list-with-random-pointer/
// Copy List with Random Pointer

// Approach - 1 (Using Hashmap) [Leetcode]
// T.C = O(n)
// S.C (extra space) = O(n)
class Solution {
    public:
    Node *copyList(Node *head) {
        unordered_map<Node* , Node*> mp;
        Node* temp = head;
        
        while(temp) {
            Node* copy = new Node(temp -> data);
            mp[temp] = copy;
            temp = temp -> next;
        }
        temp = head;
        while(temp){
            mp[temp] -> next = mp[temp -> next];
            mp[temp] -> arb = mp[temp -> arb];
            temp = temp -> next;
        }
        return mp[head];
    }
};






// Approach - 2 (codestorywithMIK)
// T.C = O(n)
// S.C = O(n) (because we used space in original linked list)
// Extra Space = O(1) (because we didn't used extra space for result, and the space for original linked list is not taken into account)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return NULL;
        }
        Node* curr = head;
        // Adding clone nodes between the original nodes
        while(curr) {
            Node* currNext = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = currNext;
            curr = currNext;
        }
        // Deep copy of random pointers
        curr = head;
        while(curr && curr->next) {
            if(curr->random == NULL) {
                curr->next->random = NULL;
            } else {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        // Recovering new copied linked list
        Node* newHead = head->next;
        Node* newCurr = newHead;
        curr = head;
        while(curr && newCurr) {
            curr->next = curr->next ? curr->next->next : NULL;
            newCurr->next = newCurr->next ? newCurr->next->next : NULL;
            
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};
