// Question Link :- https://www.geeksforgeeks.org/problems/reverse-a-stack/1
// Reverse a Stack

// Recursive Approach - 1
// T.C = O(n^2)
// S.C = O(n) Auxiliary Space (we took extra one temp stack)
class Solution{
public:
    queue<int>ans;
    void Reverse(stack<int> &St){
        if(St.empty()) {
            return;
        }
        ans.push(St.top());
        St.pop();

        Reverse(St);
        
        while (!ans.empty()){
            St.push(ans.front());
            ans.pop();
        }
    }
};




// Recursive Approach - 2
// T.C = O(n^2)
// S.C = O(1)
class Solution{
public:
    void insertAtBottom(stack<int>& St, int element) {
        if(St.empty()) {
            St.push(element);
            return;
        }
        
        int currTop = St.top();
        St.pop();
        insertAtBottom(St, element);
        St.push(currTop);
    }

    void Reverse(stack<int> &St){
        if(St.empty()) {
            return;
        }
        int top = St.top();
        St.pop();
        Reverse(St);

        insertAtBottom(St, top);
    }
};




// Iterative Approach
// T.C = O(n)
// S.C = O(n)
class Solution{
public:
    void Reverse(stack<int> &St){
        vector<int>arr; 
        while (!St.empty()){
            arr.push_back(St.top());
            St.pop();
        }
        int n = arr.size();
        for (int i = 0; i < n; i++){
            St.push(arr[i]);
        }
    }
};
