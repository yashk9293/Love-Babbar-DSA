// Question Link :- https://www.geeksforgeeks.org/problems/height-of-heap5025/1
// Height of Heap

// T.C = O(logN)
// S.C = O(1)
class Solution{
public:
    int heapHeight(int N, int arr[]){
        if(N==1) {
            return 1;
        }
        int height = 0;
        while(N>1) {
            height++;
            N/=2;
        }
        return height;
    }
};