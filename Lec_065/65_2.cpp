// Question Link :- https://practice.geeksforgeeks.org/problems/k-sum-paths/1
// K Sum Paths

// T.C = O(n^2)
// S.C = O(height)
class Solution{
  public:
    void solve(Node* root, int k, int &count, vector<int> path) {
        if(root == NULL) {
            return ;
        }
        path.push_back(root->data);
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);

        //check for K Sum
        int size = path.size();
        int sum = 0;
        for(int i = size-1; i>=0; i--) {
            sum += path[i];
            if(sum == k) {
                count++;
            }
        }
        path.pop_back();
    }

    int sumK(Node *root,int k) {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};





// T.C = O(n) 
// S.C = O(height)
class Solution {
  public:
    void solve(Node *root, int k, int currentSum, unordered_map<int, int>& mp, int &count) {
        if (root == NULL) {
            return;
        }
        //subarray sum equals k jaisa code hai
        currentSum += root->data;
        if (currentSum == k) {
            count++;
        }
        if (mp.find(currentSum - k) != mp.end()) {
            count += mp[currentSum - k];
        }
        // increment karega agar map me nhi mila to (+1) se
        mp[currentSum]++;

        solve(root->left, k, currentSum, mp, count);
        solve(root->right, k, currentSum, mp, count);

       // backtrack karega..agar last pe pahuch gaya hai to piche jayega to sum me se bhi minus hoga..aur freq bhi
        mp[currentSum]--;
    }

    int sumK(Node *root, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        solve(root, k, 0, mp, count);
        return count;
    }
};
