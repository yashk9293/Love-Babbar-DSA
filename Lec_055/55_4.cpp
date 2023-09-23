// Question Link :- https://www.codingninjas.com/studio/problems/reverse-stack-using-recursion_631875
// Reverse Stack Using Recursion

// O(N^2)
void insertAtBottom(stack<int> &s, int element) {
    //basecase
    if(s.empty()) {
        s.push(element);
      	return ;
    }
    int num = s.top();
    s.pop();
    
    //recursive call
    insertAtBottom(s, element);
    
    s.push(num);
}

void reverseStack(stack<int> &stack) {
  	//base case
    if(stack.empty()) {
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    //recursive call
    reverseStack(stack);
    
    insertAtBottom(stack,num);
}