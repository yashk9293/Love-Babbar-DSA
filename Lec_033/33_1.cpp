#include<iostream>
using namespace std;

int getSum(int *arr, int n) {
    //base case
    if(n <= 0) {
        return 0;
    }
    int sum = arr[n-1] + getSum(arr, n-1);

    return sum;
}

int main() {
    int arr[5] = {3, 4, 5, 7, 8};
    int size = 5;
    int sum = getSum(arr, size);
    cout << "Sum is " << sum << endl;

    return 0;
}

// Sum is 27
