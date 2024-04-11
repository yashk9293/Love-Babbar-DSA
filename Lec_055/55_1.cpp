// Question Link :- https://www.codingninjas.com/studio/problems/delete-middle-element-from-stack_985246
// Delete middle element from stack

// Recursive Method
// T.C = O(N)
// S.C = O(N)
#include <bits/stdc++.h>

void solve(stack<int> &s, int count, int size) {
   if(count == size/2) {
      s.pop();
      return;
   }
   int num = s.top();
   s.pop();

   solve(s, count + 1, size);

   s.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	int count = 0;
   solve(inputStack, count, N);
}








// Iterative Method
// T.C = O(N)
// S.C = O(N)
void deleteMiddle(stack<int> &inputStack, int N) {
   stack<int> st;
   int count = 0;

   while (count < N / 2) {
      st.push(inputStack.top());
      inputStack.pop();
      count = count + 1;
   }
   inputStack.pop();

   while (!st.empty()) {
      inputStack.push(st.top());
      st.pop();
   }
}
