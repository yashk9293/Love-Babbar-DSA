// Question Link :- https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/
// Sum of minimum and maximum elements of all subarrays of size k.
// (Extension of Sliding Window Maximum, Leetcode 239)

#include<iostream>
#include<queue>
using namespace std;

void solve(int *arr, int n, int k) {
    deque<int> dq_max, dq_min;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        // window checking condition for dq_max
        if (!dq_max.empty() && dq_max.front() <= i - k) {
            dq_max.pop_front();
        }
        // window checking condition for dq_min
        if (!dq_min.empty() && dq_min.front() <= i - k) {
            dq_min.pop_front();
        }
        while (!dq_max.empty() && arr[i] > arr[dq_max.back()]) {
            dq_max.pop_back();
        }
        while (!dq_min.empty() && arr[i] < arr[dq_min.back()]) {
            dq_min.pop_back();
        }
        dq_max.push_back(i);
        dq_min.push_back(i);

        if (i >= k - 1) {
            cout << "min = " << arr[dq_min.front()] << " " << "max = " << arr[dq_max.front()] << endl;
            sum += arr[dq_max.front()] + arr[dq_min.front()];
        }
    }
    cout << "sum is " << sum;
}

int main() {
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    solve(arr, 7, k);
    return 0;
}


// Output :-
// min = -1 max = 7
// min = -3 max = 7
// min = -3 max = 7
// min = -3 max = 7
// sum is 18
