// Question Link :- https://www.codingninjas.com/studio/problems/delete-middle-element-from-stack_985246
// Delete middle element from stack

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