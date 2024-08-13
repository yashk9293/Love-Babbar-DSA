// Question Link :- https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
// Maximum sum of Non-adjacent nodes

                                           1   <1+4+11, max(2,4) + max(3,11)>
                                          / \
                                         /   \
                                        /     \ 
                                       /       \
                                      /         \
                               <2,4> 2           3 <3,11>
                                    /           / \
                                   /           /   \
                                  /           /     \
                                 /           /       \
                                /           /         \
                         <4,0> 4     <5,0> 5           6 <6,0>
                             /  \         / \         /  \
                            /    \       /   \       /    \
                          <0,0> <0,0> <0,0> <0,0> <0,0> <0,0>

// T.C = O(n)
// S.C = O(height)
class Solution {
  public:
    pair<int, int> solve(Node *root) {
        if(root == NULL) {
            // pair<int, int>p = make_pair(0,0);
            // return p;
            return {0,0};
        }
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        pair<int, int> res;
        // including nodes at current level
        res.first = root->data + left.second + right.second;
        // excluding nodes at current level
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
    }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) {
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};
