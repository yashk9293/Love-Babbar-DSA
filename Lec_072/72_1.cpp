// Approach - 2
// step 1 : convert bst into sorted LL LL => T.C = O(m+n), S.C = O(h1+h2)
// step 2 : merge two sorted LL => T.C = O(m+n), S.C = O(1)
// step 3 : make bst from sorted LL
// T.C = O(m+n)
// S.C = O(m+n)

// Create DLL from BST
void convertIntoSortedDLL(Node* root, Node* &head) {
    if(root == NULL) {
        return;
    }
    convertIntoSortedDLL(root->right, head);
    root->right = head;
    
    if(head != NULL) {
        head->left = root;
    }
    head = root;
    convertIntoSortedDLL(root->left, head);
}

// Merge 2 sorted LL
Node* mergeLinkedhead(Node* head1, Node* head2) {
    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            if(head == NULL) {
                head = tail = head1;
                head1 = head1->right;
            } 
            else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } 
        else {
            if(head == NULL) {
                head = tail = head2;
                head2 = head2->right;
            } 
            else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node* sortedLL_2_BST(Node* head, int n) {
    if(n <= 0 || head == NULL) {
        return NULL;
    }
    
    // int temp = n/2;
    // Node* root = head;
    // while(temp--) {
    //     root = root->right;
    // }

    // root->left = sortedLL_2_BST(head, n/2);
    // root->right = sortedLL_2_BST(root->right, n-n/2-1);
    // return root;

    Node* left = sortedLL_2_BST(head, n/2);

    Node* root = head;
    root->left = left;
    head = head->right;
    root->right = sortedLL_2_BST(head, n-n/2-1);

    return root;
}

Node* MergeBST(Node* root1, Node* root2) {
    // Step 1 : Convert BST into DLL
    Node* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    Node* head2 = NULL;
    convertIntoSortedDLL(root2, head2); 
    head2->left = NULL;

    // Merge Sorted Linked List
    Node* list = mergeLinkedhead(head1, head2);

    // Convert List into BST
    Node* result = sortedLL_2_BST(list, countNodes(list));

    return result;
}