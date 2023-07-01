// Question Link :- https://bit.ly/3EwlU6e
// Pair Sum

#include<vector>
using namespace std;
vector<vector<int> > pairSum(vector<int> &arr, int s){
   vector< vector<int> > ans;
   
   for(int i=0;i<arr.size(); i++ )
   {
   		for(int j = i+1; j<arr.size(); j++) {
        	if(arr[i] +arr[j] == s)
            {
            	vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
				ans.push_back(temp);
            }
        }
   }
   sort(ans.begin(), ans.end());
   return ans;
}






// In Pair Sum the code will become more optimized and fast if you instead sort the array in the 
// starting itself instead of using max & min function while adding to the temp array and finally sorting 
// the ans array. 

#include <bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int s) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] == s - arr[j]) {
                temp.clear();
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                ans.push_back(temp);
            }
        }
    }
    return ans;
}


// This above code will instead have everything sorted in the beginning and then just simply adding the 
// sorted pairs to the ans array.








// Aproach - 3
int i = 0;
int j = 0;
while (i < size - 1 && j < size) {
    if (arr[i] + arr[j] == 5) {
        cout << "(" << arr[i] << "," << arr[j] << ")";
        cout << endl;
        i++;
        j = i + 1;
        counter++;
    }
    else if (arr[i] + arr[j] != 5) {
        j++;
    }
    else if (arr[i] + arr[j] > 5) {
        // i++;
        break;
    }
}
if (counter == 0) {
    cout << endl;
    cout << " No pair exists";
}




// Input :-
// 5 5
// 1 2 3 4 5

// Output :-
// 1 4
// 2 3

// Here, 1 + 4 = 5
//       2 + 3 = 5
// Hence the output will be, (1,4) , (2,3).