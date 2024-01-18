// Question Link :- https://leetcode.com/problems/search-in-rotated-sorted-array
// Search in Rotated Sorted Array

class Solution {
public:
    int find_pivot(vector<int>& nums, int s, int e) {
        while(s < e) {
            int mid = s + (e-s)/2;
            if(nums[mid] > nums[e]) {
                s = mid+1;
            } else {
                e = mid;
            }
        }
        return e;
    }
    
    int binary_search(vector<int>& nums, int s, int e, int target) {
        while(s<=e) {
            int mid = s + (e-s)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                s = mid+1;
            else
                e = mid-1;
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
