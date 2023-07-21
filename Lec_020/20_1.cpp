// Merge 2 arrays and store them in the 3rd array in ascending order

#include<iostream>
#include<vector>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[]) {
    int i = 0, j = 0;
    int k = 0;
    while( i<n && j<m) {
        if(arr1[i] < arr2[j]){
            arr3[k++] = arr1[i++];
            // k++;
            // i++;
        }
        else{
            arr3[k++] = arr2[j++];
            // k++;
            // j++;
        }
    }

    //copy first array k element ko
    while(i<n) {
        arr3[k++] = arr1[i++];
        // k++;
        // i++;
    }

    //copy kardo second array k remaining element ko
    while(j<m) {
        arr3[k++] = arr2[j++];
        // k++;
        // j++;
    }
}

void print(int ans[], int n) {
    for(int i=0; i<n; i++) {
        cout<< ans[i] <<" ";
    }
    cout << endl;
}

int main() {
    int arr1[5] = {1,3,5,7,9};
    int arr2[3] = {2,4,6};
    int arr3[8] = {0};
    merge(arr1, 5, arr2, 3, arr3);
    print(arr3, 8);
    return 0;
}

// Output :-
// 1 2 3 4 5 6 7 9 











// Question Link :- https://leetcode.com/problems/merge-sorted-array/description/
class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = 0, j = 0, k = 0;
        int nums3[m + n];
        while (i < m && j < n) {
            if (nums1[i] > nums2[j]) {
                nums3[k] = nums2[j];
                j++;
                k++;
            }
            else {
                nums3[k] = nums1[i];
                i++;
                k++;
            }
        }
        while (i < m) {
            nums3[k] = nums1[i];
            i++;
            k++;
        }
        while (j < n) {
            nums3[k] = nums2[j];
            j++;
            k++;
        }
        // extra thing, baad baki sab same hai upar wala code se
        // upar wala me alad array banakar ouput dena tha, aur is que me arr1 me hi add karke output dena tha
        for (i = 0; i < m + n; i++) {
            nums1[i] = nums3[i];
        }
    }
};