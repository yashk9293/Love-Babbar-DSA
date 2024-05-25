// Question Link :- https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
// Count ways to reach the n'th stair

// giving TLE because, the above program will be solved by dp which takes less time
// as compared to recursion.

class Solution {
    public:
    int countWays(int nStairs) {
        // base case
        if(nStairs==0 || nStairs==1) {
            return 1;
        }
        // Recursive call
        int ans = countWays(nStairs-1) + countWays(nStairs-2);
    
        return ans;
    }
};
