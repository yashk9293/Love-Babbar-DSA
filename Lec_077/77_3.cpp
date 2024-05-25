// Question Link :- https://leetcode.com/problems/construct-target-array-with-multiple-sums/
// Construct Target Array With Multiple Sums (Rohit Negi)

// T.C = O(NlogN)
// S.C = O(N)

// correct solution but Getting TLE
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq;
        long long sum = 0;
        for(int i=0; i<target.size(); i++) {
            pq.push(target[i]);
            sum+=target[i];
        }
        long long maxEle, remSum, element;
        while(pq.top() != 1){
            maxEle = pq.top();
            pq.pop();
            remSum = sum - maxEle;
            // base case
            if(remSum <=0 || remSum >= maxEle) {
                return 0;
            }
            element = maxEle - remSum;
            pq.push(element);
            sum = remSum + element;
        }
        return true;
    }
};




// Optimised
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq;
        long long sum = 0;
        for(int i=0; i<target.size(); i++) {
            pq.push(target[i]);
            sum+=target[i];
        }
        long long maxEle, remSum, element;
        while(pq.top() != 1){
            maxEle = pq.top();
            pq.pop();
            remSum = sum - maxEle;
            // base case
            if(remSum <=0 || remSum >= maxEle) {
                return 0;
            }
            element = maxEle % remSum;
            // edge case
            if(element == 0 && remSum != 1) {
                return 0;
            }
            pq.push(element);
            sum = remSum + element;
        }
        return true;
    }
};