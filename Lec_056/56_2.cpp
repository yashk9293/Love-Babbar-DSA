// Question Link :- https://leetcode.com/problems/largest-rectangle-in-histogram/
// Largest Rectangle in Histogram (Aditya Verma)

// Algorithm:
// 1. Find NSL Index array (nslIndex)
// 2. Find NSR Index array (nsrIndex)
// 3. Then width[i] = nsrIndex[i] - nslIndex[i] - 1
// 4. Then area[i] = histogram[i] * width[i]
// 5. Then mah = maximum element of 'area' array


// T.C = O(n)
// S.C = O(3n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Nearest smaller to right
        vector<int> right;
        stack<pair<int,int>> s1;
        for(int i=n-1; i>=0; i--){
            if(s1.empty()){
                right.push_back(n);          // here in nsr we will push n, not -1
            }
            else if(!s1.empty() && s1.top().first < heights[i]){
                right.push_back(s1.top().second);
            }
            else if(!s1.empty() && s1.top().first >= heights[i]){
                while(!s1.empty() && s1.top().first >= heights[i]){
                    s1.pop();
                }
                if(s1.empty()){
                    right.push_back(n);
                }
                else{
                    right.push_back(s1.top().second);
                }
            }
            s1.push({heights[i],i});
        }
        reverse(right.begin(),right.end());   // reverse
        
        // Nearest smaller to left
        vector<int> left;
        stack<pair<int,int>> s2;
        for(int i=0; i<n;i++){
            if(s2.empty()){
                left.push_back(-1);
            }
            else if(!s2.empty() && s2.top().first < heights[i]){
                left.push_back(s2.top().second);
            }
            else if(!s2.empty() && s2.top().first >= heights[i]){
                while(!s2.empty() && s2.top().first >= heights[i]){
                    s2.pop();
                }
                if(s2.empty()) {
                    left.push_back(-1);
                }
                else {
                    left.push_back(s2.top().second);
                }
            }
            s2.push({heights[i],i});
        }
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            int width = right[i]-left[i]-1;
            ans = max(ans, width *(heights[i]));
        }
        return ans;
    }
};