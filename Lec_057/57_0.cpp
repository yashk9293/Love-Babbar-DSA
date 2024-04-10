// Question Link :- https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
// The Celebrity Problem


// Approach - 1
// T.C. = O(n)
// S.C. = O(n)
class Solution  {
    private:
    bool knows(vector<vector<int> >& M, int a, int b, int n) {
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n)  {
        stack<int> s;
        //step1: push all element in stack
        for(int i=0; i<n; i++) {
            s.push(i);
        }   
        
        //step2: get 2 elements and copare them
        
        while(s.size() > 1) {
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M, a, b, n)){
                s.push(b);
            }
            else {
                s.push(a);
            }
        }
        int ans = s.top();
        //step3: single element in stack is potential celebrity
        //so verify it
        
        int zeroCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[ans][i] == 0)
                zeroCount++;
        }
        //all zeroes
        if(zeroCount != n)
            return -1;
        
        //column check
        int oneCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        if(oneCount != n-1)
            return -1;
        
        return ans;
    }
};





// Approach - 2
// T.C. = O(n)
// S.C. = O(1)
class Solution  {
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        int start =0, end = n-1;
        
        while(start<end) {
            if(M[start][end]==0) {
                end--;
            }
            else {
                start++;
            }
        }
        int candidate = start;
        
        int zeroCount=0;
        for(int i=0; i<n; i++){
            if(M[candidate][i] != 0) {
                return -1;
            }
            if(i != start && M[i][candidate] != 1) {
                return -1;
            }
        }
        return candidate;
    }
};