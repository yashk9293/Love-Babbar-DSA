// Question Link :- https://bit.ly/3dm6bdZ
// Find duplicate element in the array

int findDuplicate(vector<int> &arr)  {
    int ans = 0;
    // XOR ing all array elements
    for(int i=0; i<arr.size(); i++) {
        ans = ans^arr[i];
    }
    // XOR [1, n-1]
    for(int i=1; i<arr.size(); i++) {
        ans = ans^i;
    }
	return ans;
}


// the above code can be written in 1 for loop *********
int findDuplicate(vector<int> &arr)  {
    int ans=0;
    for( int i = 0; i < arr.size(); i++){
        ans = ans^arr[i]^i; 
    }
	return ans;
}


// ------------------- Method-2 ----------------------
int findDuplicate(vector<int> &arr) {
    int size = arr.size();
    int b = size*(size+1)/2;
    int v=0;
    for(int i=0;i<size;i++) {
        v=v+arr[i];
    }
    int ans = size-(b-v);
    return ans;   
}




// Input :-
// 4
// 5
// 4 2 1 3 1
// 7
// 6 3 1 5 4 3 2
// 6 
// 5 1 2 3 4 2  
// 9
// 8 7 2 5 4 7 1 3 6


// Output :-
// 1
// 3
// 2
// 7