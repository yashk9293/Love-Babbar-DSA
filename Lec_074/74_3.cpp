// Question Link :- https://leetcode.com/problems/sort-an-array/
// Sort an Array

// Love babbar
// Approach - 1 (Heap Sort)
// T.C = O(nlogn)
// S.C = O(n)
class Solution {
public:
    void heapify(vector<int>& arr, int n, int i){
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if(l < n and arr[l] > arr[largest]){
            largest = l;
        }
        if(r < n and arr[r] > arr[largest]){
            largest = r;
        }
        if(largest != i){
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
    }
    
    void buildHeap(vector<int>& arr, int n){
        for(int i=n/2-1; i>=0; i--){
            heapify(arr, n, i);
        }
    }
    
    vector<int> sortArray(vector<int>& arr) {
        int n = arr.size();
        buildHeap(arr, n);
        while(n > 0) {
            swap(arr[0], arr[n-1]);
            n--;
            heapify(arr, n, 0);
        }
        return arr;
    }
};




// codestorywithMIK
// Approach - 2 (Counting Sort)
// T.C = O(n+k)
// S.C = O(n)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minE = *min_element(begin(nums), end(nums));
        int maxE = *max_element(begin(nums), end(nums));
        
        unordered_map<int, int> mp;
        
        for(int &num : nums)
            mp[num]++;
        
        int i = 0;
        
        for(int num = minE; num <= maxE; num++) {
            
            while(mp[num] > 0) {
                nums[i] = num;
                i++;
                mp[num]--;
            }
            
        }
        
        return nums;
    }
};
