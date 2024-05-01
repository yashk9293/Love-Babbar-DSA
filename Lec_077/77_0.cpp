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







// Approach - 3
// T.C = O(N*K*log(K))
// S.C = O(K)
#include<bits/stdc++.h>
class node {
    public:
    int data;
    int row, col;

    node(int val, int i, int j) {
        data = val;
        row = i;
        col = j;
    }
};

class compare {
    public:
    bool operator() (node* a, node*b) {
        return a->data > b-> data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    priority_queue<node*, vector<node*>, compare> minHeap;
    int mini = INT_MAX;
    int maxi = INT_MIN;

    // Step 1 : Creating a Min Heap for starting element of each list and tracking mini/maxi value of each list
    for(int i=0; i<k; i++) {
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }

    int start = mini;
    int end = maxi;

    // Step 2 : process ranges
    while(!minHeap.empty()) {
        // fetching minimum element
        node* temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;

        // range or answer updation
        if(maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }
        // checking whether next element exists or not
        if(temp->col+1 < n) {
            maxi = max(maxi, a[temp->row][temp->col+1]);
            minHeap.push(new node(a[temp->row][temp->col+1], temp->row, temp-> col+1));
        }
        else {
            break;
        }
    }
    return (end-start)+1;
}