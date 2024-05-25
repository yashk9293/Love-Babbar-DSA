// Question Link :- https://www.codingninjas.com/studio/problems/number-of-inversions_6840276
// Inversion Count (in this ques vector is given) STRIVER

// Naive Approach (Brute force)
// T.C : O(N^2)
// S.C : O(1)
int numberOfInversions(vector<int>&a, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

// Input:
// A = [5, 3, 2, 1, 4], N = 5
// Output:
// 7







// Optimal Solution (Merge Sort)
// T.C : O(nlogn)
// S.C : O(n)
int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;      // temporary array
    int left = low;        // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }
    // if elements on the left half are still left //
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return cnt;    // Modification 3
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) {
        return cnt;
    }
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int>&a, int n) {
    return mergeSort(a, 0, n - 1);
}