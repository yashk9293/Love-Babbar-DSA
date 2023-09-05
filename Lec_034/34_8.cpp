// SELECTION SORT using Recursion

// space complexity - O(1)
// time complexity - O(n^2)
// used for low size array

/*
                    0   1   2   3   4
  arr[] -           64  25  12  22  11

                     _____swap______
                    |               |
round 1 :           64  25  12  22  11
                   i=0  ---------------

                        _swap_
                        |    |
round 2 :           11  25  12  22  64
                       i=1  ----------

                            _swap_
                            |    |
round 3 :           11  12  25  22  64
                           i=2  ------

                                __
                                ||
round 4 :           11  12  22  25  64
                               i=3 ----

*/

// n-1 rounds tak chalega


#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

void selectionSort(int* arr, int n) {
    if(n==0 || n==1) {
        return;
    }
    int min = INT_MAX;
    int ind = 0;
    for(int i = 0; i<n; i++) {
        if(arr[i]<min) {
            min = arr[i];
            ind = i;
        }
    }
    swap(arr[0], arr[ind]);
    
    selectionSort(arr+1, n-1);  // array from next element is passed into the pointer array parameter 
                                // in the function selectionSort, so the size will ne n-1.
}

int main() {
    int n;
    cin>>n;

    int* arr = new int[n];
    for(int i= 0;i<n;i++) {
        cin>>arr[i];
    }
    
    cout<<"Before sorting"<<endl;
    for(int i= 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    
    selectionSort(arr,n);
    
    cout<<endl<<"After sorting"<<endl;
    for(int i= 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    
    delete [] arr;
    return 0;
}




// Flowchart

/*
Start
  |
  |__ Set minimum element to first element in the list
  |
  |__ Repeat for each element in the list:
  |     |
  |     |__ Compare current element with minimum element
  |     |
  |     |__ If current element is smaller than minimum, set minimum to current element
  |
  |__ Swap minimum element with first element in the list
  |
  |__ Repeat steps 2 to 4 for the remaining elements in the list
  |
  |__ End

*/



// Input :-

// 5
// 4 8 5 3 1




// Output  :-

// Before sorting
// 4 8 5 3 1 
// After sorting
// 1 3 4 5 8 