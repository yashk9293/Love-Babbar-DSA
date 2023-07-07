/* sorted array -> 1 2 3 4 8 9
   sorted and rotated array -> 4 8 9 1 2 3

 |
 |          /
 |        /
 |      /
 |                 /
 |               /
 |             /    
 |_____________________

*/

#include<iostream> 
using namespace std;

int getPivot(int arr[], int n) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s<e) {
        if(arr[mid] >= arr[0]) {
            s = mid+1;
        }
        else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int main() {
    int arr[5] = {3, 8, 10, 1, 17};
    cout << "Pivot is " << getPivot(arr, 5) << endl;
}


// Output :-
// Pivot is 3






// ---------------------- Method - 2 ------------------------
int getpivot(int arr[],int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s<e){
        if(arr[mid]<arr[n-1]){
            e = mid;
        }
        else if(arr[mid]>arr[n-1]){
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return s;
}