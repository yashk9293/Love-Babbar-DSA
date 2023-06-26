// Question Link :- https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Find all the elements in an array which appears twice.

vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
	    // int *arr = new int[size + 1];
        int arr[size+1];
	    std::fill_n(arr, size + 1, 0);
	    for (int i = 0; i < size; i++) {
		    arr[nums[i]]++;
       	    }
	    vector<int> ans;
	    for (int i = 0; i <= size; i++) {
		    if (arr[i] >= 2)
			    ans.push_back(i);
	    }
	    return ans;
}




// ---------------------- Method - 2 ---------------------------
vector<int> findDuplicates(vector<int>& nums) {
    unordered_map<int,int> mp;
    vector<int> vec;
    for(int i=0; i<nums.size(); i++) {
        mp[nums[i]]++;
    }
    for(auto it:mp) {
        if(it.second ==2) {       //  or  if(it.second >1)  or  if(it.second >=2)
            vec.push_back(it.first);
        }
    }
    return vec;
}




// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]


// Input: nums = [1,1,2]
// Output: [1]