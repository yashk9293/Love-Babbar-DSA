// Question Link :- https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650
// Count Ways To Reach The N-th Stairs

// giving TLE in 2 testcases because, the above program will be solved by dp which takes less time
// as compared to recursion.

#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    // base case
    if(nStairs < 0)
        return 0;
    
    if(nStairs == 0)
        return 1;
    
    // Recursive call
    int ans = countDistinctWays(nStairs-1)
        + countDistinctWays(nStairs-2);
    
    return ans;
}