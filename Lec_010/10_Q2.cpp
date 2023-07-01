// Question Link :- https://bit.ly/3y01Zdu
// Find unique element in array


// BRUTE FORCE APPROACH - to check every element if there count is 1 it means it unique and return that element
// int findUnique(int *arr, int size) {
//     int count=0;
//     for(int i=0;i<size;i++){
//         count=0;
//         for(int j=0;j<size;j++){
//             if(arr[i]==arr[j]){
//                 count++;
//             }
//         }
//         if(count==1){
//             return arr[i];
//         }
//     }
// }



// ________________
// |  XOR Property |
// |_______________|
// |  a ^ a = 0    |
// |  0 ^ a = a    |
// |_______________|

int findUnique(int *arr, int size) {
   	int ans = 0;
    for(int i = 0; i<size; i++) {
        ans = ans^arr[i];
    }
    return ans;
}

// Input :-
// 2 3 1 6 3 6 2
// 2 4 7 2 7
// 1 3 1 3 6 6 7 10 7

// Output :-
// 1
// 4
// 10