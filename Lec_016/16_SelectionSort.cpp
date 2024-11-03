// Question Link :- https://www.naukri.com/code360/problems/selection-sort_981162
// Selection Sort

// T.C = O(n^2)
// S.C = O(1)
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

#include<vector>
using namespace std;
void selectionSort(vector<int>& arr, int n) {   
    for(int i = 0; i < n-1; i++ ) {
        int minIndex = i;
        
        for(int j = i+1; j<n; j++) {
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
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
