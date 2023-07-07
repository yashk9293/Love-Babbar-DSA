// Question Link :- https://bit.ly/3Ioexjh 
// First and last occurence of an Element In Sorted Array

#include<vector>
using namespace std;
int firstOcc(vector<int>& arr, int n, int key) {
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {
        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOcc(vector<int>& arr, int n, int key) {
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {
        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]) {        //Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {        //left me jao
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    pair<int,int> p;
    p.first = firstOcc(arr, n, k);
    p.second = lastOcc(arr, n, k);
    return p;
}


// Input :-
// 2
// 6 3
// 0 5 5 6 6 6
// 8 2
// 0 0 1 1 2 2 2 2


// Output :-
// -1 -1 
// 4 7




// If the question was to find the total no. of occurences then 
// the answer should come by = lastOcc - firstOcc + 1

// 5 4 7 7 7 7 7 9    -> array is sorted
//     |       |
//     V       V
//     2       6

// therefore total occurences = (6 - 2) + 1 = 5
// for total no. of occurences we also need to return 0 when start and end are -1
// otherwise it will calculate count as end - start + 1 i.e. 1

int first = firstOccurence(arr, n, key);
int last = lastOccurence(arr, n, key);
int total_no_of_occurences;
if(first == -1 && last == -1)  
// Element not found in array. This -1 is nothing but, ans = -1 that we took for finding first and last occurences
{
    total_no_of_occurences = 0;
}
else
{
    total_no_of_occurences = (last - first) + 1;
}
cout << total_no_of_occurences << endl;