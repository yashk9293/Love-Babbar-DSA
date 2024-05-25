// Question Link :- https://leetcode.com/problems/kth-largest-element-in-an-array
// Kth Largest Element in an Array

// Approach - 1
// T.C = O(nlogn)
// S.C = O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(begin(nums), end(nums), greater<int>());
        return nums[k - 1];
    }
};





// Approach - 2
// T.C = O(nlogk)
// S.C = O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //the smaller the earlier to be popped
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num : nums){
            pq.push(num);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};






// Approach - 3 (Quick Select [Hoare's Partition])
// Average T.C = O(n)
// Worst Case = O(n^2)
// S.C = O(n)
class Solution {
public: 
    int partition_algo(vector<int>& nums, int L, int R) {
        int P = nums[L];
        int i = L+1; // 0
        int j = R; // 0
        while(i <= j) {
            if(nums[i] < P && nums[j] > P) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if(nums[i] >= P) {
                i++;
            }
            if(nums[j] <= P) {
                j--;
            } 
        }
        swap(nums[L], nums[j]);
        return j;    // P is at jth index
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int L = 0;
        int R = nums.size()-1;
        int pivot_idx = 0;
        // kth largest pivot element = nums[k-1] (descending order me partition karenge)
        while(true) {
            pivot_idx = partition_algo(nums, L, R);
            if(pivot_idx == k-1) {
                break;
            } else if(pivot_idx > k-1) {  // for eg need 2nd largest, we get 4th largest
                R = pivot_idx - 1;
            } else {
                L = pivot_idx + 1;
            }
        }
        return nums[pivot_idx];
    }
};
