// Question Link :- https://bit.ly/3s3fAOu
// Sort 0s, 1s and 2s

// Approach 1 - Data replacement
Node* sortList(Node *head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while(temp != NULL) {
        if(temp -> data ==0) {
            zeroCount++;
        }
        else if(temp -> data == 1) {
            oneCount++;
        }
        else if(temp -> data == 2) {
            twoCount++;
        }
        temp = temp -> next;
    }

    temp = head;
    while(temp != NULL) {
        if(zeroCount != 0) {
            temp -> data = 0;
            zeroCount--;
        }
        else if(oneCount != 0) {
            temp -> data = 1;
            oneCount--;
        }
        else if(twoCount != 0) {
            temp -> data = 2;
            twoCount--;
        }
        temp = temp -> next;
    }
    return head;
}







// Approach 1 - Changing links
void insertAtTail(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}


Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    //merge 3 sublist
    
    // 1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
        oneTail -> next = twoHead -> next;
    }
    else {
        //1s list -> empty
        //one's list is empty, so we'll connect 0 list with 2s directly;
        zeroTail -> next = twoHead -> next;
    }
    
    twoTail -> next = NULL;
    
	//setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    //to prevent memory leak, due to allocation of dummy node so we need to delete it.
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}

// T.C = O(n) + O(1) + O(1) = O(n)
// S.C = O(1)