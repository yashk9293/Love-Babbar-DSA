// Question Link :- https://www.codingninjas.com/studio/problems/reverse-the-string_799927
// Reverse the String

void reverse(string& str, int i, int j) {
	if(i>j) {
		return;
	}
	swap(str[i], str[j]);
	i++;
	j--;

	reverse(str, i, j);
}


string reverseString(string str) {
	reverse(str, 0, str.length()-1);
	return str;
}