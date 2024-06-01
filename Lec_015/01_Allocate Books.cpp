// Question Link :- https://www.naukri.com/code360/problems/allocate-books_1090540
// Allocate Books


// Similar problems with same code
// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557 [11]
// https://leetcode.com/problems/split-array-largest-sum/ [10]


// Linear Search (Brute Force)
// T.C = O(N * (sum(arr[])-max(arr[])+1))
// S.C = O(1)
int countStudents(vector<int> &arr, int pages) {
    int n = arr.size();
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {  //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) {
        return -1;
    }
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for (int pages = low; pages <= high; pages++) {
        if (countStudents(arr, pages) == m) {
            return pages;
        }
    }
    return low;
}







// Binary Search (Optimal Solution)
// T.C = O(N * log(sum(arr)-max(arr[])+1))) 
// S.C = O(1)
int countStudents(vector<int> &arr, int pages) {
    int n = arr.size();
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {   //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) {
        return -1;
    }
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}