// Question Link :- https://www.codingninjas.com/studio/problems/two-stacks_983634
// Two Stacks


// Approach - 1: n/2 size of both stacks


// Approach - 2: Space optimised
class TwoStack {
	int *arr;
    int top1;
    int top2;
    int size;
public:
    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        //atleast a empty space present
        if(top2 - top1 > 1 ) {
            top1++;
            arr[top1] = num;
        } 
    }

    // Push in stack 2.
    void push2(int num) {
         if(top2 - top1 > 1 ) {
            top2--;
            arr[top2] = num;
        } 
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
		if( top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
		if( top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else {
            return -1;
        }
    }
};




/*
In the pop() operation, we just decremented the value of top. We didnt actually cleared the memory 
taken by the top most element. Hence, after poping out the element, we can still access that element from 
the array through it's index.

Memory toh aise b allocate constructor k through ho gyi h.. hm top ko pichr le ja rhn islye take age 
koi element aye toh wo usko overwrite kr de toh memory free nhi krna h  bs jagah ban rhi ane wle elements 
k lye...
*/