// Question Link :- https://www.codingninjas.com/studio/problems/merge-k-sorted-lists_992772
// Merge k sorted lists



// Approach - 1 (Naive Approach)
// T.C = O(N * logN)
// S.C = O(N)           Where 'N' is the total number of Nodes

Node* mergeKLists(vector<Node*> &listArray) {
    int k = listArray.size();
    if (k == 0) {
        return NULL;
    }
    vector<int> ans;

    // Insert nodes in a ans array.
    for (int i = 0; i < k; i++) {
        Node* curNode = listArray[i];
        while (curNode != NULL) {
           ans.push_back(curNode->data);
           curNode =  curNode->next;
        }
    }

    // Sort the array.
    sort(ans.begin(), ans.end());

    Node *head = NULL, *tail = NULL;

    // Convert into a linked list.
    for (int i = 0; i < ans.size(); i++) {
        Node *newNode = new Node(ans[i]);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}




// Approach - 2
// T.C = O(N * logK)
// S.C = O(K)

class compare {
    public:
        bool operator () (List* a, List* b) {
            return a->data > b->data;
        }
};

List* mergeSortedLists(vector<List* > kLists) {
    priority_queue<List*, vector<List*>, compare> minHeap;
    int K = kLists.size();

    // Empty list
    if(K == 0) {
        return NULL;
    }
    // Step 1 : Creating a Min Heap
    for(int i=0; i<K; i++) {
        if(kLists[i] != NULL) {
            minHeap.push(kLists[i]);
        }
    }
    List* head = NULL;
    List* tail = NULL;

    // Step 2 : Comparing next nodes
    while(minHeap.size() > 0) {
        List* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL) {
            minHeap.push(top->next);
        }
        if(head == NULL) {
            head = tail = top;
        } 
        else {
            tail->next = top;
            tail = top;
        }
    }
    return head;
}