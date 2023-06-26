// Reverse Array

#include<iostream>
using namespace std;

void reverse(int arr[], int n) {
    int start = 0;
    int end = n-1;
    while(start<=end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[], int n) { 
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[6] = {1,4,0,5,-2,15};
    int brr[5] = {2,6,3,9,4};
    reverse(arr, 6);
    reverse(brr, 5);
    printArray(arr, 6);
    printArray(brr, 5);
    return 0;
}





// reverse the array
// #include <iostream>
// using namespace std;

// int main() {
//     int a[3]={3,2,7};
//     cout<<"{";
//     for(int i=3;i;i--) { 
//         cout<<a[i-1];
//         if(i>1) {
//             cout<<",";
//         }
//     }
//     cout<<"}"<<endl;
//     return 0;
// }






// Reverse the Array
// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// int main() {
//     int c=3 ,d=4;
//     swap(c,d);
//     cout<<c<<d<<endl;
//     int a[3]={3,2,7};
//     cout<<"{";
//     for(int i=0;i<3;i++) { 
//         //a[i]=a[2-i];
//         cout<<a[2-i];
//         if(i<2){
//             cout<<",";
//         }
//     }
//     cout<<"}"<<endl;
//     return 0;
// }