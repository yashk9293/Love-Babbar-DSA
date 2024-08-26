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
    while(i < arr1.size()) {
        solution.push_back(arr1[i]);
        i++;
    }
    while(j < arr2.size()) {
        solution.push_back(arr2[j]);
        j++;
    }
    return solution;
}


Node* makeBST(vector<int>& result, int l, int r) {
    if(l > r) {
        return NULL;
    }
    int mid = (l+r)/2;
    Node* node = new Node(result[mid]);
    node->left = makeBST(result, l, mid-1);
    node->right = makeBST(result, mid+1, r);
    return node;
}

Node* MergeBST(Node* root1, Node* root2) {
    vector<int> arr1;
    vector<int> arr2;
    inOrder(root1, arr1);
    inOrder(root2, arr2);

    vector<int> result = mergeArrays(arr1, arr2);
    Node* answer = makeBST(result, 0, result.size()-1);

    return answer;
}
