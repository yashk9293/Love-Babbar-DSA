// Question Link :- https://www.naukri.com/code360/problems/bubble-sort_980524
// Bubble Sort

// T.C = O(n^2)
// S.C = O(1)

// best case - already sorted    -> tc = O(n)
// worst case - reverse sorted
/*
                    0   1  2  3   4  5
  arr[] -           10  1  7  6  14  9


Round 1 :           10  1  7  6  14  9
                    |___| 

                    1  10  7  6  14  9
                       |___|

                    1  7  10  6  14  9
                          |___|
                    
                    1  7  6  10  14  9
                             |___| -> ignore

                    1  7  6  10  14  9
                                 |___|

round 1 result -->  1  7  6  10  9  14
                                    --


Round 2 :           1  7  6  10  9  14
                    |__|

                    1  7  6  10  9  14
                       |__|

                    1  6  7  10  9  14
                          |___|
                        
                    1  6  7  10  9  14
                             |___|

round 2 result -->  1  6  7  9  10  14
                                --

                    
Round 3 :           1  6  7  9  10  14
                    |__|

                    1  6  7  9  10  14
                       |__|

                    1  6  7  9  10  14
                          |__|

round 3 result -->  1  6  7  9  10  14
                            --


Round 4 :           1  6  7  9  10  14
                    |__|

                    1  6  7  9  10  14
                       |__|

round 4 result -->  1  6  7  9  10  14
                         --


Round 5 :           1  6  7  9  10  14
                    |__|

round 5 result -->  1  6  7  9  10  14
                      --


selection sort --  in every round the smallest value takes their correct place.
bubble sort - in every round the largest value takes their correct place.
n-1 rounds tak chalega
*/


#include<vector>
using namespace std;


void bubbleSort(vector<int>& arr, int n) {   
    for(int i = 0; i<n-1; i++) {   
        
        for(int j = 0; j<n-i-1; j++) {  // Note here j is going till (n-i)th index, as in this sort largest value takes their correct place.
            //process element till n-i-1 th index
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }  
    }
}



// Optimized Code
void bubbleSort(vector<int>& arr, int n) {   
    for(int i = 0; i<n-1; i++) {
        bool swapped = false;
       
        for(int j = 0; j<n-i-1; j++) { 

            //process element till n-i th index
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false) {
            //already sorted
            break;
        }
           
    }
}



// 1. bubble sort is a stable algorithm, as we are not using <=, so it will not swap same elements
// 2. bubble sort is in place sort because it does not use additional space
