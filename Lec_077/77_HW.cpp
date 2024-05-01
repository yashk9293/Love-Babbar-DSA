// Question Link :- https://www.codingninjas.com/studio/problems/rearrange-string_982765
// Rearrange string

// Approach - 2
// T.C = O(N * log(N))
// S.C = O(N)
#include <queue>
string reArrangeString(string &s) {
	int n = s.size();
	vector<int> hash(26, 0);

	for (char character : s) {
		hash[character - 'a']++;
	}
	priority_queue<pair<int, char>> maxHeap;

	// Declare prev to store previous character store in answer.
	pair<int, char> prev = {-1, '@'};


	for (int i = 0; i < 26; i++) {
		if (hash[i] == 0)
			continue;
		maxHeap.push({hash[i], 'a' + i});
	}
	string answer = "";
	while (maxHeap.empty() == false) {
		pair<int, char> curMax = maxHeap.top();
		maxHeap.pop();

		// Decrease frequency of top item of heap from 1 and character of top item to answer.
		curMax.first--;
		answer.push_back(curMax.second);

		// Push previous character back to heap if its frequency > 0.
		if (prev.first > 0) {
			maxHeap.push(prev);
		}

		// Make current most frequent as previous character.
		prev = curMax;
	}

	string notValid = "not possible";

	// Check if size of answer is equal to s or not.
	if (answer.size() != s.size()) {
		return notValid;
	}
	return answer;
}







// Approach - 2 (Sorting Approach or Hashing Approach)
// T.C = O(N)
// S.C = O(1)
#include <algorithm>
bool check(string &s) {
	int n = s.size();
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {
			return false;
		}
	}
	return true;
}

string reArrangeString(string &s) {
	vector<pair<int, char>> store;
	int n = s.size();
	vector<int> hash(26, 0);

	// Store frequency of all characters in hash array.
	for (char character : s) {
		hash[character - 'a']++;
	}

	// Use store to sort characters based on frequency.
	for (int i = 0; i < 26; i++) {
		store.push_back({hash[i], 'a' + i});
	}

	// Sort the frequency of characters in decreasing order.
	sort(store.rbegin(), store.rend());
	s = "";
	// Revert back to all characters in string such that characters having high frequency will come first.
	for (auto &pair : store) {
		for (int i = 0; i < pair.first; i++) {
			s.push_back(pair.second);
		}
	}

	// Use to pointers left and right to merger characters from front and middle of sorted string.
	int left = 0, right = (n - 1) / 2 + 1;
	string answer = "";

	while (left <= (n - 1) / 2) {
		answer.push_back(s[left]);
		if (right < n) {
			answer.push_back(s[right]);
		}
		left++;
		right++;
	}

	string notValid = "not possible";

	// If string still contains two same adjacent characters then return not possible.
	if (check(answer) == false) {
		return notValid;
	}
	return answer;
}

