// Question Link :- https://www.codingninjas.com/studio/problems/permutations-of-a-string_985254
// Permutation of a String

// T.C = O(N! x N)
// S.C = O(1)
#include <bits/stdc++.h>
void solve(int index, string &str, vector<string>& ans) {
    //base case
    if(index == str.length()){
        ans.push_back(str);
        return ;
    }
    for (int i = index; i < str.length(); i++) {
        swap(str[index], str[i]);
        solve(index + 1, str, ans);
        // backtracking
        swap(str[index], str[i]);
    }
}

vector<string> generatePermutations(string &str) {
    vector<string> ans;
    solve(0, str, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
