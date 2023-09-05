// BUBBLE SORT using Recursion


// space complexity - O(1)
// time complexity - O(n^2)

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



#include<iostream>
using namespace std;

void sortArray(int *arr, int n) {
    //base case - already sorted
    if(n == 0 || n == 1) {
        return ;
    }

    //1 case sovle karlia - largest element ko end me rakh dega
    for(int i=0; i<n-1; i++) {
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    //Recursive Call
    sortArray(arr, n-1);

}

int main() {
    int arr[5] = {2,5,1,6,9};
    sortArray(arr,5);
    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Output :-
// 1 2 5 6 9 