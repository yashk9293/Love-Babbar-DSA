// Question Link :- https://www.codingninjas.com/studio/problems/k-th-largest-sum-contiguous-subarray_920398
// K-th Largest Sum Subarray

// Approach - 1 (BRUTE FORCE)
// T.C = O(n^2(log n))
#include<algorithm>
int getKthLargest(vector<int> &arr, int k) {
    vector<int> sumStore;
    int n= arr.size();
    for(int i=0; i<n; i++) {
        int sum=0;
        for(int j=i; j<n; j++) {
            sum+=arr[j];
            sumStore.push_back(sum);
        }
    }
    sort(sumStore.begin(), sumStore.end());

    return sumStore[sumStor.size()-k];
}





// Approach - 2
// T.C = O(n^2 log k)
#include<bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k) {
	priority_queue<int, vector<int>, greater<int>> mini;
	int n=arr.size();

	for(int i=0; i<n ; i++) {
		int sum=0;
		for(int j=i; j<n; j++) {
			sum+=arr[j];
			if(mini.size()<k) {
				mini.push(sum);
			}
			else {
                if(sum>mini.top()) {
				    mini.pop();
				    mini.push(sum);
			}
		}
	}
	return mini.top();
}