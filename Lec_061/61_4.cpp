// Question Link :- https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1
// Question Link :- https://leetcode.com/problems/gas-station
// Circular tour

// T.C = O(N)
// S.C = O(1)
class Solution{
  public:
  
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n) {
        int deficient = 0;
        int balance = 0;
        int start =0;
       
        for(int i=0; i<n; i++) {
            balance += p[i].petrol - p[i].distance;  // balance = balance + p[i].petrol - p[i].distance
            if(balance < 0) {
                start = i+1;                         // Note : here we should not do start++;
                deficient += balance;
                balance = 0;
            }
        }
        if(balance + deficient >= 0) { 
            return start;
        }
        return -1;
    }
};
