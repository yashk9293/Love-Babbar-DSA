// Question Link :-  https://www.codingninjas.com/studio/problems/count-inversions_615
// Count Inversions (in this ques arr[] is given) STRIVER

// Optimal Solution (Merge Sort)
// T.C : O(nlogn)
// S.C : O(n)

long long merge(long long arr[], int low, int mid, int high){
    int left = low, right = mid+1, k = 0;
    int temp[(high - low + 1)];

    //Modification 1: cnt variable to count the pairs:
    long long invCount = 0;

    while ((left <= mid) && (right <= high)){
        if (arr[left] <= arr[right]){
            temp[k] = arr[left];
            ++k;
            ++left;
        }
        else{
            temp[k] = arr[right];
            invCount += (mid - left + 1); //Modification 2
            ++k;
            ++right;
        }
    }

    // if elements on the left half are still left //
    while (left <= mid){
        temp[k] = arr[left];
        ++k;
        ++left;
    }

    // if elements on the right half are still left //
    while (right <= high){
        temp[k] = arr[right];
        ++k;
        ++right;
    }

    // transfering all elements from temporary to arr //
    for (left = low, k = 0; left <= high; left++, k++){
        arr[left] = temp[k];
    }
    return invCount;   // Modification 3
}

long long mergeSort(long long arr[], int low, int high){
    long long invCount = 0;
    if (low >= high){
        return invCount;
    }
    int mid = (low + high) / 2;
    invCount += mergeSort(arr, low, mid);
    invCount += mergeSort(arr, mid + 1, high);
    invCount += merge(arr, low, mid, high);
    return invCount;
}

long long getInversions(long long arr[], int n){
    return mergeSort(arr, 0, n - 1);
}
