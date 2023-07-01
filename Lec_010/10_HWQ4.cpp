// Question Link :- https://bit.ly/3DfQW0s
// Sort 0 1 2
// Also Striver SDE sheet || Dutch National Flag Algorithm

#include <bits/stdc++.h>

// ---------- Method - 1 ------------
void sort012(int *arr, int n) {
    int num0 = 0, num1 = 0;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == 0)
            num0++;
        else if (*(arr + i) == 1)
            num1++;
    }
    for (int i = 0; i < n; i++) {
        if (num0) {
            *arr = 0;
            num0--;
        }
        else if (num1) {
            *arr = 1;
            num1--;
        }
        else
            *arr = 2;

        *arr++;
    }
}





// --------- Method - 2 -----------
void sort012(int *arr, int n) {
    //   Write your code here
    int i = 0;
    int mid = 0;
    int k = n - 1;
    while (mid <= k) {
        if (arr[mid] == 0) {
            swap(arr[i], arr[mid]);
            i++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else if (arr[mid] == 2) {
            swap(arr[mid], arr[k]);
            k--;
        }
    }
}

// -------- OR ----------- 

void sort012(int *arr, int n) {
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        switch (arr[mid]) {
        case 0:
            swap(arr[low], arr[mid]);
            low++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid], arr[high]);
            high--;
            break;
        }
    }
}




// Input :-
// 2
// 6
// 0 1 2 2 1 0
// 7
// 0 1 2 1 2 1 2

// Output :-
// 0 0 1 1 2 2
// 0 1 1 1 2 2 2