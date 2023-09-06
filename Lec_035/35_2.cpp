// Question Link :- https://www.codingninjas.com/studio/problems/merge-sort_920442
// Merge Sort

void merge(vector<int> &arr, int s, int e) {
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void solve(vector<int> &arr, int s, int e) {
    //base case
    if(s >= e) {
        return;
    }
    int mid = (s+e)/2;

    //left part sort karna h 
    solve(arr, s, mid);
    
    //right part sort karna h 
    solve(arr, mid+1, e);

    //merge
    merge(arr, s, e);

}

void mergeSort(vector < int > & arr, int n) {
    solve(arr, 0, n-1);
}