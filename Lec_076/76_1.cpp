// Question Link :- https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_975379
// Merge K Sorted Arrays

// Approach - 1 (BRUTE FORCE)
// T.C = O(n*k log(n*k))
// create ans array -> O(1)
// insert all element (n*k) into ans array -> O(n*k)
// sort ans array -> O(n*k log(n*k))





// Approach -  2 (Better Approach)
// Divide and Conquer using two-pointer technique of merging two sorted arrays
// T.C = O((N*K) log(K))
// S.C = O((N*K) log(K))
// There are log (K) levels because in each level the ‘K’ arrays are divided into half. And O(N * K) space is required to store the ans. 

vector<int> merge(vector<int>&a, vector<int>&b) {
    vector<int>ans; 
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    while(i < n and j < m) {
        if(a[i] < b[j]){
            ans.push_back(a[i]);
            i += 1;
        }
        else {
            ans.push_back(b[j]);
            j += 1;
        }
    }
    while(i < n) {
        ans.push_back(a[i]);
        i += 1;
    }
    while(j < m) {
        ans.push_back(b[j]);
        j += 1;
    }
    return ans; 
}

vector<int>  mergeKSortedArraysHelper(vector<vector<int>>&kArrays, int start, int end){
    if(start == end) {  // If there is only one array.
        return kArrays[start];
    }
    if(start + 1 == end) {    // If there are only two arrays, merge them.
        return merge(kArrays[start], kArrays[end]);
    }
    int mid = start + (end - start)/2;
    vector<int> first = mergeKSortedArraysHelper(kArrays, start, mid);
    vector<int> second = mergeKSortedArraysHelper(kArrays, mid + 1, end);
    
    return merge(first, second);
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k) {
    vector<int> result = mergeKSortedArraysHelper(kArrays, 0, k - 1);
    return result;
}











// Approach - 3 (Optimal) using Heaps
// T.C = O(n*k log(k))
// S.C = O(k)[heap] + O(n*k)[result vector] = O(n*k)
#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k) {
    vector<int> result; 
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int> >>> minHeap; 
    // O(klogk)
    for (int i = 0; i < kArrays.size(); i++) {
        minHeap.push({ kArrays[i][0], { i, 0 } }); 
    }
    // O(n*k log k)  -> n*k elements and insertion into heap takes log k
    while (!minHeap.empty()) { 
        pair<int, pair<int, int>> curr = minHeap.top();  // Remove the minimum element from the heap.
        minHeap.pop(); 
  
        // i is the array number and j is the index of the removed element in the ith array.
        int i = curr.second.first; 
        int j = curr.second.second; 
    
        result.push_back(curr.first);     // Add the removed element to the output array.
  
        // If the next element of the extracted element exists, add it to the heap.
        if (j + 1 < kArrays[i].size()) {
            minHeap.push({ kArrays[i][j + 1], { i, j + 1 } }); 
        }
    }
    return result; 
}
