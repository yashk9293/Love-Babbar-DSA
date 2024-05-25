// Question link :- https://www.codingninjas.com/studio/problems/smallest-range-from-k-sorted-list_1069356
// Smallest Range From K Sorted List



// Approach - 1 (BRUTE FORCE)
// T.C = O(N^3 * K^3)
// S.C = O(N*K)   
// Where ‘N’ is the number of elements present in each list and ‘K’ is the number of lists.
#include <limits.h>
#include <algorithm>

// This function will return true if given start end include at least element from each list
bool validRange(vector<vector<int>> &a, int start, int end, int k, int n) {
    for (int i = 0; i < k; ++i) {
        bool found = false;
        for (int j = 0; j < n; ++j) {
            // Check if any element lie in our current range
            if (start <= a[i][j] && a[i][j] <= end) {
                found = true;
                break;
            }
        }
        // If we can not find any elements which lie in our range then we return false
        if (!found) {
            return false;
        }
    }
    // If for each element in the list we always find some element which lie in our range then we return true
    return true;
}

int kSorted(vector<vector<int>> &a, int k, int n) {
    vector<int> list;
    // Storing all the elements in 1D list
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            list.push_back(a[i][j]);
        }
    }
    sort(list.begin(), list.end());
    int ans = INT_MAX;
    // Check for all possible range
    for (int i = 0; i < list.size(); ++i) {
        for (int j = i; j < list.size(); ++j) {
            int start = list[i];
            int end = list[j];
            // If current range is valid then compare its len with minimum length
            if (validRange(a, start, end, k, n)) {
                int len = end - start + 1;
                ans = min(ans, len);
            }
        }
    }

    return ans;
}





// Approach - 2
// T.C = O(N * K^2)
// S.C = O(K)
// using any data structure , and inside that everytime we have to find min and max from that data structure







// Question link :- https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists
// Smallest Range Covering Elements from K Lists


// Rohit Negi
// Approach - 3
// T.C = O(N*K*log(K))
// S.C = O(K)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        int minimum;
        int maximum = INT_MIN;
        // calculating minimum and maximum for first K elements
        for(int i=0; i<nums.size(); i++) {
            minHeap.push(make_pair(nums[i][0], make_pair(i,0)));
            maximum = max(maximum, nums[i][0]);
        }
        minimum = minHeap.top().first;
        // creating ans vector
        vector<int> ans(2);
        ans[0] = minimum;
        ans[1] = maximum;
        // Now traversing the lists
        while(minHeap.size() == nums.size()) {
            pair<int, pair<int, int>> curr = minHeap.top();
            minHeap.pop();
            int element = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;
            if(j+1 < nums[i].size()) {
                minHeap.push({nums[i][j+1], {i, j+1}});
                maximum = max(maximum, nums[i][j+1]);
                minimum = minHeap.top().first;

                if(maximum-minimum < ans[1]-ans[0]) {
                    ans[0] = minimum;
                    ans[1] = maximum;
                }
            }
        }
        return ans;
    }
};
