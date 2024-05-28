// Question Link :- https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Find First and Last Position of Element in Sorted Array

// Approach - 1 (Binary Search)
// T.C = O(logn)
// S.C = O(1)
class Solution {
public:
    int firstOcc(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int ans = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                ans = mid;
                r = mid-1;
            }
            else if(nums[mid] > target) {
                r = mid-1;
            }
            else if(nums[mid] < target) {
                l = mid+1;
            }
        }
        return ans;
    }
    
    int lastOcc(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int ans = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                ans = mid; //possibly my answer
                l = mid+1;   //but lets look at right more
            }
            else if(nums[mid] > target) {
                r = mid-1;
            }
            else if(nums[mid] < target) {
                l = mid+1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = firstOcc(nums, target);
        int r = lastOcc(nums, target);
        
        return {l, r};
    }
};






// Approach - 2 (Using STL)
// T.C = O(logn)
// S.C = O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin();
        if (l == r) {
            return {-1, -1};
        }
        return {l, r - 1};
    }
};








// If the question was to find the total no. of occurences then 
// the answer should come by = lastOcc - firstOcc + 1

// 5 4 7 7 7 7 7 9    -> array is sorted
//     |       |
//     V       V
//     2       6

// therefore total occurences = (6 - 2) + 1 = 5
// for total no. of occurences we also need to return 0 when start and end are -1
// otherwise it will calculate count as end - start + 1 i.e. 1

int first = firstOccurence(arr, n, key);
int last = lastOccurence(arr, n, key);
int total_no_of_occurences;
if(first == -1 && last == -1) { 
// Element not found in array. This -1 is nothing but, ans = -1 that we took for finding first and last occurences
    total_no_of_occurences = 0;
}
else {
    total_no_of_occurences = (last - first) + 1;
}
cout << total_no_of_occurences << endl;
