#include <bits/stdc++.h>
using namespace std;


// Merging without creating 2 new array
void merge(int *a, int s, int e) {
    int mid = s + (e - s) / 2;
    int l1 = mid - s + 1;
    int l2 = e - mid;

    int idx1 = s;
    int idx2 = mid + 1;
    int k = s;
    while (idx1 < (s + l1) && idx2 <= e) {
        if (a[idx1] <= a[idx2]) {
            idx1++;
        }
        else if (a[idx1] > a[idx2]) {
            swap(a[idx1++], a[idx2]);
            int curr = idx2;
            for (int i = idx2 + 1; i <= e; i++) {
                if (a[curr] > a[i]) {
                    swap(a[curr++], a[i]);
                }
                else {
                    break;
                }
            }
        }
    }
}
void MergeSort(int *a, int s, int e) {
    // Base case
    if (s >= e) {
        return;
    }
    int mid = s + (e - s) / 2;

    // left part sort
    MergeSort(a, s, mid);
    // right part sort
    MergeSort(a, mid + 1, e);
    // merge the two sorted arays array
    merge(a, s, e);
}

void solve() {
    int a[8] = {3,4,6,14,7,8,9,12};
    int n = 8;
    MergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout<<endl;
}
int main() {
    int t = 1; // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}


// Output :-
// 3 4 6 7 8 9 12 14