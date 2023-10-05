// Question Link :- https://practice.geeksforgeeks.org/problems/queue-reversal/1
// Queue Reversal

// Approach - 1 : Using Stack
// T.C = O(n)
// S.C = O(n)
class Solution {
public:
    queue<int> rev(queue<int> q) {
        stack<int> s;

        while (!q.empty()) {
            int element = q.front();
            q.pop();
            s.push(element);
        }
        while (!s.empty()) {
            int element = s.top();
            s.pop();
            q.push(element);
        }
        return q;
    }
};







// Approach - 2 : Using recursion
// T.C = O(n)
// S.C = O(n)
class Solution {
    private:
    void reverseQueue(queue<int>& q) {
        // Base case
        if (q.empty())
            return;
 
        // Dequeue current item (from front) 
        int data = q.front();
        q.pop();
 
        // Reverse remaining queue 
        reverseQueue(q);
 
        // Enqueue current item (to rear) 
        q.push(data);
    }

    public:
    queue<int> rev(queue<int> q) {
        reverseQueue(q);

        return q;
    }
};