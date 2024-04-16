// Question Link :- https://www.geeksforgeeks.org/convert-bst-min-heap/
// Convert BST to Min Heap

// T.C = O(n)
// S.C = O(n)

// Youtube Link :- https://youtu.be/_9F2VgZcvdw?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA

void inorder(BinaryTreeNode* root, vector<int> &ans) {
	// base case
	if(root==NULL) {
		return;
	}
	inorder(root->left, ans);
	ans.push_back(root->data);
	inorder(root->right, ans);
}

void preorderFill(BinaryTreeNode* root, int &index, vector<int> &ans) {
	if(root==NULL) {
		return;
	}
	root->data=ans[index++];
	preorderFill(root->left, index, ans);
	preorderFill(root->right, index, ans);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root) {
	vector<int> ans;
	inorder(root, ans);

	int index=0;
	preorderFill(root, index, ans);

	return root;
}