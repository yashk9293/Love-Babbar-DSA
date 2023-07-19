// space complexity - O(1)
// time complexity - O(n^2)

// best case - already sorted    -> tc = O(n)
// worst case - reverse sorted

// 0   1  2  3  4  5  6
// 10  1  7  4  8  2  11

/*
Round 1 :  1 < 10 -> left side
  i=1      10 -> left place
            0th index -> 1 copy karde

Round 2 :  1  10 | 7  4  8  2  11
           7<10 -> left
           7>1 -> right

                      3
Round 3 :  1  7  10 | 4  8  2  11
           4<10 -> left

                         4
Round 4 :  1  4  7  10 | 8  2  11

                            5
Round 5 :  1  4  7  8  10 | 2  11

Round 6 :  1  2  4  7  8  10 | 11

Result ->  1  2  4  7  8  10  11
*/
// n-1 round

#include<vector>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    
    for(int i = 1; i<n; i++) {
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--) {
            
            if(arr[j] > temp) {
                //shift
                arr[j+1] = arr[j];
            }
            else { // ruk jao
                break;
            }
            
        }
        //copy temp value
        arr[j+1] = temp;  
    } 
}




//         i
// 1  10 | 7  4  8  2  11

// using while loop
void insertionSort(int n, vector<int> &arr){
    int i=1;
    while(i<n){
       int j=i-1;
        int temp=arr[i];
        while(j>=0){
            if(arr[j]>temp) {
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
            j--;
        }
        i++;
        arr[j+1]=temp;
    }
}

