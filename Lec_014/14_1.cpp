// Question Link :- https://leetcode.com/problems/search-in-rotated-sorted-array
// Search in Rotated Sorted Array

class Solution {
public:
    int find_pivot(vector<int>& nums, int l, int r) {
        while(l < r) {
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return r;
    }
    
    int binary_search(vector<int>& nums, int l, int r, int target) {
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = find_pivot(nums, 0, n-1);
        
        if( target >= nums[pivot] && target <= nums[n-1]) {
        //BS on second line
            return binary_search(nums, pivot, n-1, target);
        }
        else { 
        //BS on first line
            return binary_search(nums, 0, pivot - 1, target);
        }
    }
};
