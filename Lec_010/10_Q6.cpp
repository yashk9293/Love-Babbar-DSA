// it same homework question no. - 3
// Question Link :- https://bit.ly/3GbgVs3
// Finding Triplets

#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>>ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        int target = K - arr[i];
        int front = i + 1;
        int back = n - 1;

        while (front < back) {
            int sum = arr[front] + arr[back];
            // Finding answer which starts from arr[i].
            if (sum < target) {
                front++;
            }
            else if (sum > target) {
                back--;
            }
            else {
                int x = arr[front];
                int y = arr[back];
                ans.push_back({arr[i], arr[front], arr[back]});

                // Incrementing front pointer until we reach a different number.
                while (front < back && arr[front] == x) {
                    front++;
                }
                // Decrementing last pointer until we reach a different number.
                while (front < back && arr[back] == y) {
                    back--;
                }
            }
        }

        // Ensuring that we don't encounter duplicate values for arr[i].
        while (i + 1 < n && arr[i] == arr[i + 1]) {
            i++;
        }
    }
    return ans;
}






// ---------------- Method - 2 ------------------------------
void findTriplets(vector<int> arr, int n, int K) {
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 2; i++) {
        int start = i + 1;
        int end = n - 1;
        while (start < end) {
            if (arr[i] + arr[start] + arr[end] == K) {
                cout << arr[i] << " " << arr[start] << " " << arr[end] << endl;
                return;
            }
            else if (arr[i] + arr[start] + arr[end] < K)
                start++;
            else
                end--;
        }
    }
    cout << -1 << endl;
}

int _tmain(int argc, _TCHAR *argv[]) {
    vector<int> nums = {1, 1, 2, 2, 1, 1};
    findTriplets(nums, 6, 4);
    return 0;
}






// ------------------ Method - 3 --------------------
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int>> pairtriplet(vector<int> &arr,int n){
    vector<vector<int>> ans;
    int triplet=12;
  	for(int i=0;i<arr.size();++i){
      for(int j=i+1;j<arr.size();++j){ 
        if(i!=j){
          if(arr[i]+arr[j]+arr[j+1]==triplet){
            vector<int> temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            temp.push_back(arr[j+1]);
            // sort(temp.begin(),temp.end());
            ans.push_back(temp);
          }
        }
      }
    }
    // sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int> arr={1,2,3,4,5,4,1,9,2};
    vector<vector<int>> ans=pairtriplet(arr,arr.size());
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j)
            cout<<ans[i][j]<<" ";
        cout<<endl; 
    }
    return 0;
}
