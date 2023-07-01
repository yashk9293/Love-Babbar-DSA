//swap alternative elements in the array
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i<n; i++ ) {
        cout<< arr[i] <<" ";
    }
    cout<<endl;
}

void swapAlternate(int arr[], int size) {
    for(int i = 0; i<size; i+=2 ) {
        if(i+1 < size) {
            swap(arr[i], arr[i+1]);
        }
    }
}

int main() {

    int even[8] = {5,2,9,4,7,6,1,0};
    int odd[5] = {11, 33, 9, 76, 43};

    swapAlternate(even, 8);
    printArray(even, 8);

    cout << endl;

    swapAlternate(odd, 5);
    printArray(odd, 5);
    return 0;
}



// Output :-
// 2 5 4 9 6 7 0 1 
// 33 11 76 9 43 



// Method-2
int main() {
    int a[5]={3,4,6,2,8};
    for(int i=0;i<4;i++){
        if(i%2==0){
        swap(a[i],a[i+1]);
        cout<<a[i]<<" "<<a[i+1]<<" ";}
    }
    cout<<a[4];
    return 0;
}


// Method-3
void swapAlt(int arr[], int size) {
  int a=0,b=1;
  while(b<size){
    swap(arr[a],arr[b]);
    a += 2;
    b += 2;
  }
}
int main() {
  int a[5]={12, 45, 89, 37, 11};
  cout<<"Original: ";
  for(int i = 0; i<5; i++) {
    cout<< a[i] <<" ";
  }
  swapAlt(a,5);
  cout << endl << "Reverse: ";
  for(int i=0; i<5; i++) {
    cout<< a[i] <<" ";
  }
}