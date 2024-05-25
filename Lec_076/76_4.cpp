// Question Link :- https://www.interviewbit.com/problems/magician-and-chocolates/
// Magician and Chocolates

// Brute Force
// T.C = O(k.n)
// S.C = O(n)
// find maximum through traversing, store the answer and update by A[i]/2
// do this K times.
// return the answer.


// Optimal Approach
// T.C = O(k logn)
// S.C = O(n)
int Solution::nchoc(int k, vector<int> &nums) {
    priority_queue<int> maxHeap;
    for(int &num : nums) {
        maxHeap.push(num);
    }
    long long maxChoco = 0;
    while(k) {
        int currChoco = maxHeap.top();
        maxChoco += currChoco;
        maxHeap.pop();
        maxHeap.push(currChoco/2);
        k--;
    }
    return maxChoco% 1000000007;
}