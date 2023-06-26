// Question Link :- https://leetcode.com/problems/unique-number-of-occurrences/description/
// HW Ques - 1, Unique Occurrences using array


bool uniqueOccurrences(vector<int>& arr) {
	std::map<int, int> mapCounter;
	for (int i = 0; i < arr.size(); i++){
        mapCounter[arr[i]]++;
    }
	vector<int> vec;
	std::vector<int>::iterator i;
	for (auto it = mapCounter.begin(); it != mapCounter.end(); it++) {	
		i = std::find(vec.begin(), vec.end(), it->second);
		if (i != vec.end())
			return false;
		else
			vec.push_back(it->second);
	}
    return true;
}




// ----------------------- Method - 2 -------------------------
bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> mp;
    unordered_set<int> st;                          // -> unordered_set stores unique key elements
    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]]++;
    }
    for (auto it : mp) {
        st.insert(it.second);
    }
    if (st.size() == mp.size()) {
        return true;
    }
    return false;
}




// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

// Input: arr = [1,2]
// Output: false

// Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
// Output: true