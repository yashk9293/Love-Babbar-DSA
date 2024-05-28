// Question Link :- https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
// Peak Index in a Mountain Array

// Approach - 1 (Linear Search)
// T.C = O(n)
//S.C = O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
       //You can remove i < n-1 check because array is gauranteed to be Mountain (given in qn)
        while(i < n-1 && arr[i] < arr[i+1]) {
            i++;
        }
        return i;
    }
};



// Approach - 2 (Binary Search)
// T.C = O(logn)
// S.C = O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1;
        int mid=s+(e-s)/2;

        while(s<e) {     // s<=e no use as s=e is checking twice
            if(arr[mid]<arr[mid+1]){
                s=mid+1;
            }
            else{
                e=mid;  // here not e= mid - 1; because (mid-1)th element can be peak element
            }
            mid=s+(e-s)/2;
        }
        return mid;
    }
};




// Input: arr = [0,1,0]
// Output: 1


// Input: arr = [0,2,1,0]
// Output: 1


// Input: arr = [0,5,10,2]
// Output: 2
