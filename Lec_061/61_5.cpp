// Question Link :- https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/
// Interleave the first half of the queue with second half


// Approach - 1 : Using Queue
// T.C = O(n)
// S.C = O(n)
void interLeaveQueue(queue < int > & q) {
    queue<int> newQ;
    
    int n = q.size()/2;

    // Step-1: Fetch first half elements from input queue and push into a newQueue
    for(int i=0;i<n;i++) {
        int val=q.front();
        q.pop();
        newQ.push(val);
    }

    // Step-2: Push alternative elements in input queue itself
    while(!newQ.empty()) {
        int val=newQ.front();
        newQ.pop();
        q.push(val);

        val=q.front();
        q.pop();
        q.push(val);
    }
}








// Approach - 1 : Using Stack
// T.C = O(n)
// S.C = O(n)
void interLeaveQueue(queue<int> &q){
    stack<int> s;
    int half = q.size()/2;
    
    // push first half elements in the stack
    for(int i = 0; i < half; i++){
        s.push(q.front());
        q.pop();
    }

    // enqueue all the elements in the stack into queue
    while (!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
    // dequeue first half elements of the queue and enqueue them back
    for(int i = 0; i < half; i++){
        q.push(q.front());
        q.pop();
    }

    // Again push first half elements of the queue into stack
    for(int i = 0; i < half; i++){
        s.push(q.front());
        q.pop();
    }

    // Interleave the elements of the stack and the queue
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}