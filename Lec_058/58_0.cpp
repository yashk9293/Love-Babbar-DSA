// Question Link :- https://www.codingninjas.com/studio/problems/n-stacks-in-an-array_1164271
// N Stacks In An Array

// Approach - 1: n/k size for each stack.

// Approach - 2:
#include <bits/stdc++.h> 
class NStack {
    int* arr;
    int* next;
    int* top;
    int freeSpot;

    public:
    // Initialize your data structure.
    NStack(int N, int S) {
        arr = new int[S];
        next = new int[S];
        top = new int[N];
        freeSpot = 0;

        // top initialise
        for(int i=0;i<N;i++){
            top[i] = -1;
        }

        // next initialise
        for(int i=0;i<S;i++){
            next[i] = i+1;
        }
        next[S-1] = -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m) {
        // check stack overflow
        if(freeSpot == -1){
            return false;;
        }

        // update int index
        int index = freeSpot;

        // push the element in arr at index
        arr[index] = x;

        // update freeStop
        freeSpot = next[index];

        // update next 
        next[index] = top[m-1];

        // update top
        top[m-1] = index;

        return true;

    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m) {
        // check stack underflow
        if(top[m-1] == -1){
            return -1;
        }
        // apply all step of push in reverse order
        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freeSpot;

        freeSpot = index;

        return arr[index];
    }
};




// T.C = O(1)
// S.C = O(s+n)