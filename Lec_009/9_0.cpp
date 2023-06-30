// Linear Search in Array

#include<iostream>
#include<limits.h>
using namespace std;

bool search(int arr[], int size, int key) {
    for( int i = 0; i<size; i++ ) {
        if( arr[i] == key) {
            return 1;
        }
    }
    return 0;
}


int main() {
    int arr[10] = { 5, 7, -2, 10, 22, -2, 0, 5, 22, 1};
    cout <<" Enter the element to search for " << endl; 
    int key;
    cin >> key;
    bool found = search(arr, 10, key);
    if( found ) {
        cout <<" Key is present "<< endl;
    }
    else{
        cout <<" Key is absent " << endl;
    }
    return 0;
}





//We can initialize the array with any value by using the fill_n command 

#include<iostream>
using namespace std;

int main() {
    int array[100];

    //To initialize the array with value'1'.
    fill_n(array, 100, 1);

    //To check the array input (kewaal 5 hi kari h print)
    for(int i = 0; i <= 5; i++){
        cout << array[i] << endl;
    }
}





// Find Min/Max in Array

#include<iostream>
using namespace std;

int getMin(int num[], int n) {
    int mini = INT_MAX;
    for(int i = 0; i<n; i++) {
        mini = min( mini, num[i]);
        
        // if(num[i] < min){
        //     min = num[i];
        // }
    }
    // returning min value
    return mini;
}

int getMax(int num[], int n) {
    int maxi = INT_MIN;
    for(int i = 0; i<n; i++) {
        maxi = max(maxi, num[i]);
        // if(num[i] > max){
        //   max = num[i];
        // }
    }
    //returning max value
    return maxi;
}

int main() {
    int size;
    cin >> size;
    int num[100];
    //taking input in array
    for(int i = 0; i<size; i++) {
        cin >> num[i];
    }
    cout << " Maximum value is " << getMax(num, size) << endl;
    cout << " Minimum value is " << getMin(num, size) << endl;
    return 0;
}