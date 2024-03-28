// Question Link :- https://www.codingninjas.com/studio/problems/h_920474
// Merge Two BSTs

// Approach - 1
// step 1 : store the inorder of both the bst
// step 2 : merge two sorted arrays
// step 3 : make bst from inorder sorted array
// T.C = O(m+n)
// S.C = O(m+n)

void inOrder(Node* root, vector<int>& ans) {
    if(root == NULL) {
        return;
    }

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

vector<int> mergeArrays(vector<int> arr1, vector<int> arr2) {
    if(arr1.size() == 0 || arr2.size() == 0) {
        return (arr1.size()) ? arr1 : arr2;
    }

    int i=0, j=0;
    vector<int> solution;

    while(i<arr1.size() && j<arr2.size()) {
        if(arr1[i] < arr2[j]) {
            solution.push_back(arr1[i]);
            i++;
        } else {
            solution.push_back(arr2[j]);
            j++;
        }
    }
    
    while(i<arr1.size()) {
        solution.push_back(arr1[i]);
        i++;
    }
    
    while(j<arr2.size()) {
        solution.push_back(arr2[j]);
        j++;
    }

    return solution;
}

Node* createBST(vector<int> &arr, int start, int end) {
    if(start > end) {
        return NULL;
    }

    int mid = start + (end-start)/2;
    Node* temp = new Node(arr[mid]);

    temp->left = createBST(arr, start, mid-1);
    temp->right = createBST(arr, mid+1, end);

    return temp;
}

Node* MergeBST(Node* root1, Node* root2) {
    vector<int> arr1;
    vector<int> arr2;

    inOrder(root1, arr1);
    inOrder(root2, arr2);

    vector<int> resultArray = mergeArrays(arr1, arr2);
    Node* answer = createBST(resultArray, 0, resultArray.size()-1);

    return answer;
}