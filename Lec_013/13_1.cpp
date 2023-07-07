// Question Link :- https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
// Peak Index

#include<vector>
using namespace std;

class Solution {
public:
    int peakindex(vector<int> v) {
        int s = 0, e = v.size() - 1;
        int mid = (s + e) / 2; // or mid = s+(e-s)/2
        while (s < e) { // s<=e no use as s=e is checking twice
            if (v[mid] < v[mid + 1])
                s = mid + 1;
            else
                e = mid; // here not e= mid - 1; because (mid-1)th element can be peak element

            mid = (s + e) / 2; // or mid = s+(e-s)/2
        }
        return s;
    }

    int peakIndexInMountainArray(vector<int> &arr) {
        return peakindex(arr);
    }
};

// or 

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1;
        int mid=s+(e-s)/2;

        while(s<e){
            if(arr[mid]<arr[mid+1]){
                s=mid+1;
            }
            else{
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return mid;
    }
};




// ---------------- Method - 2 -------------------
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n = a.size();
        //Peak exists somewhere in between start and end
        int start = 1, end = n-2;     // Note -> end is going till n-2
        while(start<=end){
            int mid = start + (end-start)/2;
            if(a[mid] > a[mid-1] && a[mid] > a[mid+1]) 
                return mid;
            else if(a[mid-1] > a[mid]) 
                end = mid-1;
            else 
                start = mid+1;
        }
        return -1;
    }
};




// --------------- Method - 3 --------------------
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //using my own algorithm
        int s=0, e=arr.size()-1;
        int i=0;
        while(s < e) {
            if(arr[i] < arr[i+1]) {
                i++;
            }
            else
                break;
        }
        return i;
    }
};








// Input: arr = [0,1,0]
// Output: 1


// Input: arr = [0,2,1,0]
// Output: 1


// Input: arr = [0,5,10,2]
// Output: 2