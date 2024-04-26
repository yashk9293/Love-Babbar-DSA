// Question Link :- https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_975379
// Merge K Sorted Arrays

// Approach - 1 (BRUTE FORCE)
// T.C = O(n*k log(n*k))
// create ans array -> O(1)
// insert all element (n*k) into ans array -> O(n*k)
// sort ans array -> O(n*k log(n*k))


// Approach - 2
// T.C = O(n*k log(k))
// S.C = O(k) + O(n*k) = O(n*k)
#include <bits/stdc++.h> 
class node {
    public:
    int data;
    int i, j;

    node(int data, int row, int col){
        this->data = data;
        this->i = row;
        this->j = col;
    }
};

class compare {
    public:
    bool operator() (node*a, node*b) {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    priority_queue<node*, vector<node*>, compare> minHeap;

    // Step 1 : Insert all first elements in minHeap
    for(int i=0; i<k; i++) {
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    // Step 2 : Comparing each node and moving further in the array
    while(minHeap.size()>0) {
        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        if(j+1 < kArrays[i].size()) {
            node* next = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }
    return ans;
}



// Approach - 2 (different style)
#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k) {
    vector<int> result; 
    // Create a min heap to store atmost k heap nodes at a time.
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > minHeap; 
  
    for (int i = 0; i < kArrays.size(); i++) {
        minHeap.push({ kArrays[i][0], { i, 0 } }); 
    }
    while (minHeap.empty() == false) { 
        // Remove the minimum element from the heap.
        pair<int, pair<int, int> > curr = minHeap.top(); 
        minHeap.pop(); 
  
        // i is the array number and j is the index of the removed element in the ith array.
        int i = curr.second.first; 
        int j = curr.second.second; 
    
        // Add the removed element to the output array.
        result.push_back(curr.first); 
  
        // If the next element of the extracted element exists, add it to the heap.
        if (j + 1 < kArrays[i].size()) {
            minHeap.push({ kArrays[i][j + 1], { i, j + 1 } }); 
        }
    }
    return result; 
}









// Approach -  3
// T.C = O((N*K) log(K))
// S.C = O((N*K) log(K))
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
    // If there is only one array.
    if(start == end){
        return kArrays[start];
    }
    // If there are only two arrays, merge them.
    if(start + 1 == end) {
        return merge(kArrays[start], kArrays[end]);
    }
    
    int mid = start + (end - start)/2;
    // Divide the arrays into two halves.
    vector<int> first = mergeKSortedArraysHelper(kArrays, start, mid);
    vector<int> second = mergeKSortedArraysHelper(kArrays, mid + 1, end);
    
    // Return the final merged array.
    return merge(first, second);
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k) {
    vector<int> result = mergeKSortedArraysHelper(kArrays, 0, k - 1);
    return result;
}
