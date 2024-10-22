// Question Link :- https://www.codingninjas.com/studio/problems/sort-a-stack_985275
// Sort a Stack Using Recursion

// T.C = O(n^2)
// S.C = O(1)
void insertElement(stack<int>& St, int element) {
	if(St.empty() || element > St.top()) {
		St.push(element);
		return;
	}
	int currTop = St.top();
	St.pop();
	insertElement(St, element);
	St.push(currTop);
}

// Recursive method to sort a stack
void sortStack(stack<int> &St) {
	if(St.empty()) {
		return;
	}
	int top = St.top();
	St.pop();

	sortStack(St);  // Recursion for the remaining elements in the stack

	insertElement(St, top);  // Insert the popped element back in the sorted stack
}




// Using Iteration
// T.C = O(N^2)
// S.C = O(N)
void sortStack(stack<int> &s) {
	stack<int> aux;

    while (!s.empty()) {
        int temp = s.top();
        s.pop();

        // we willput element in aux stack in ascending order to get the St elements in descending order
        while (!aux.empty() && temp > aux.top()) {
            s.push(aux.top());
            aux.pop();
        }
        aux.push(temp);
    }

    // Transfer back from aux to s
    while (!aux.empty()) {
        s.push(aux.top());
        aux.pop();
    }
}
