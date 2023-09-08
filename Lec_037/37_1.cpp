// https://www.codingninjas.com/studio/problems/subsequences-of-string_985087
// Subsequence of string

void solve(vector<string>& ans, string str, string output, int i) {
    //base case
    if(i>=str.length()) {
        if(output.length() > 0) // we don't want null output
        ans.push_back(output);
        return ;
        }
    
    //exclude
    solve(ans, str, output, i+1);
    //include
    output.push_back(str[i]);
    solve(ans, str, output, i+1);
}

vector<string> subsequences(string str){
	vector<string> ans;
    string output = "";
    solve(ans,str,output,0);
    return ans;
	
}


// Sample Input 1:
// 1 
// abc

// Sample Output 1:
// a ab abc ac b bc c




// Sample Input 2:
// 1
// bbb

// Sample Output 2:
// b b b bb bb bb bbb