// Question Link :- https://bit.ly/3rEVSK7
// Search in a rotated & Sorted array

#include<vector>
using namespace std;

int getPivot(vector<int>& arr, int n) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s<e) {
        if(arr[mid] >= arr[0]) {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(vector<int>& arr, int s, int e, int key) {
    int start = s;
    int end = e;
    int mid = start + (end-start)/2;

    while(start <= end) {
        if(arr[mid] == key) {
            return mid;
        }
        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}



int findPosition(vector<int>& arr, int n, int k)
{
    int pivot = getPivot(arr, n);
    if( k >= arr[pivot] && k <= arr[n-1]) {
        //BS on second line
        return binarySearch(arr, pivot, n-1, k);
    }
    else { 
        //BS on first line
        return binarySearch(arr, 0, pivot - 1, k);
    }
    
}








// ------------ Approach - 2 ------------------
int search(int* arr, int n, int k) {
    int s = 0 , e = n - 1 , mid;
    while( s <= e ){
        mid = s + (e - s)/2;
        if(k < arr[0]  && arr[mid] < k ) 
            s = mid + 1;
        else if(k < arr[0] && arr[mid] > k) 
            e = mid -1;
        else if(k > arr[0] && arr[mid] < k) 
            s = mid + 1;
        else if(k > arr[0] && arr[mid] > k) 
            e = mid -1;
        else 
            return mid;
    }
    return -1;
}







// --------------------- Optimal Solution ---------------------
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, mid;
        mid = (start+end)/2;
        while(start <= end){
            if(target == nums[mid]){
                return mid;
            }
            if(nums[end] > nums[mid]){
                if(nums[mid] < target && nums[end] >= target){
                    start = mid+1;
                }
                else{
                    end = mid -1;
                }
            }
            else{
                if(nums[mid] > target && nums[start] <= target){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            mid = (start+end)/2;
        }
        return -1;
    }
};




// Input :-
// 4 3
// 2 3 5 8

// Output :-
// 1




// Input :-
// 4 3
// 8 9 4 5

// Output :-
// -1

// Explanation - For the test case, 3 is not present in the array. Hence the output will be -1.
