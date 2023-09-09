// Question Link :- https://www.codingninjas.com/studio/problems/permutations-of-a-string_985254
// Permutation of a String


#include <bits/stdc++.h>
void solve(string str,int index,vector<string>& ans){  // string is passed by value.
    //base case
    if(index >= str.length()){
        ans.push_back(str);
        return ;
    }
    for (int i = index; i < str.length(); i++) {
        swap(str[index], str[i]);
        solve(str, index + 1, ans);
        // backtracking
        swap(str[index], str[i]);   // the code will work even we do not use it as because each time 
//                                     vector nums is passed by value  so  in every new call a new vector 
//                                     will be created  so even  when the nums vector is changed in future 
//                                     recursive calls it will not affect the previous nums vector.
    }
}

vector<string> generatePermutations(string &str) {
    vector<string> ans;
    int index=0;
    solve(str,index,ans);
    sort(ans.begin(), ans.end());
    return ans;
}