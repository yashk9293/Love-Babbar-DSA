// Question Link :- https://www.codingninjas.com/studio/problems/sort-a-stack_985275
// Sort a Stack Using Recursion

void sortedInsert(stack<int> &stack, int num) {
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }
    
    int n = stack.top();
    stack.pop();
    
    //recusrive call
    sortedInsert(stack, num);
    
    stack.push(n);
}

void sortStack(stack<int> &stack) {
	//base case
    if(stack.empty()) {
        return ;
    }
    int num = stack.top();
    stack.pop();

    //recursive call
    sortStack(stack);

    sortedInsert(stack, num);
}