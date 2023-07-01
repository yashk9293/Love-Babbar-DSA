// Sort 0 1

#include<iostream>
using namespace std;
void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ----------------- Love Babbar Approach -------------------
// void sortOne(int arr[], int n) {
//     int left = 0, right = n-1;
//     while(left < right) {
//         while(arr[left] == 0 && left < right )  {
//             left++;
//         }
//         while(arr[right]==1 && left < right){
//             right--;
//         }
//         //agar yha pohoch gye ho, iska matlab
//         //arr[left]==1 and arr[right]==0
//         if(left<right) {  // or if(arr[left]==1 && arr[right]==0 && left<right)
//             swap(arr[left], arr[right]);
//             left++;
//             right--;
//         }
//     }
// }


// ----------------- Approach - 2 ---------------------
void sortOne(int arr[] , int n){
    int low = 0;
    int high = n-1;
    while(low<=high){
        if(arr[low] == 0){
            low++;
        }
        else{
            swap(arr[high],arr[low]);
            high--;
        }
    }
}


int main() {
    int arr[8] = {0,0,1,1,0,0,1,0};
    sortOne(arr, 8);
    printArray(arr, 8);
    return 0;
}


// Output:-
// 0 0 0 0 0 1 1 1