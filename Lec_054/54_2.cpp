// Implementation of Stack using Linked List

#include<iostream>
#include<stack>
using namespace std;

class Stack {
    public:

    int data;
    Stack* next;

    Stack(int data) {
        this -> data = data;
        this -> next = NULL;
    }
    
    void push(int element, Stack* &head, Stack* &tail){
        Stack *newNode = new Stack(element);
        if( head == NULL){
            //first element push
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            //assuming element is present
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void pop(Stack* &head, Stack* &tail){
        if( head == NULL){
            //if no element is present
            cout << "Stack Underflow "<<endl;
        }
        else {
            //edge case for last element
            if( head == tail){
                head = NULL;
                return;
            }
            Stack* temp = head;
            while( temp -> next != tail){
                temp = temp -> next;
            }
            temp -> next = NULL;
            tail = temp;
        }
    }

    int peek(Stack* &tail){
        if( tail == NULL){
            cout << "Stack Underflow " << endl;
        }else{
            return tail -> data;
        }
    }

    bool isEmpty(Stack* &head){
        if( head == NULL){
            return true;
        }
        else return false;
    }
};

void print( Stack* &head){
    Stack* temp = head;
    if( temp == NULL) {
        cout << temp -> data << endl;
    }
    while(temp != NULL){
        cout<< temp ->  data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    Stack *head = NULL;
    Stack *tail = NULL;
    Stack st(0);
    st.push(4,head,tail);
    st.push(8,head,tail);
    st.push(6,head,tail);
    print(head);


    cout <<"Peek element is "<< st.peek(tail) <<endl;

    st.pop(head,tail);

    print(head);
    
    cout<<"Peek element is "<<st.peek(tail) <<endl;

    st.pop(head,tail);

    print(head);

    st.pop(head,tail);

    if( st.isEmpty(head)) {
        cout << "Stack is empty "<<endl;
    }
    else {
        cout<< "Stack is not empty"<<endl;
    }

    return 0;
}



// Output :-

// 4 8 6 
// Peek element is 6
// 4 8 
// Peek element is 8
// 4 
// Stack is empty 









class Node {
	public:
		int data;
		Node* next;
		
	public:
    //constructor
	Node(int data) {
		this->data = data;
		this->next=NULL; 
	}

	//destructor
	~Node() {
		int value = this->data;
		if(this->next==NULL) {
			delete next;
			this->next=NULL;	
		}	
		cout << "Memory freed for data " << value << endl;
	}	
};


void push(Node* &top,int data)
{
	Node *temp=new Node(data);
	if(top==NULL)
	{
		top=temp;
		return;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
}

void pop(Node* &top)
{
	if(top==NULL)
	{
		cout << "stack underflow " << endl;
		return;	
	}	
	else
	{
		Node* temp=top;
		top=top->next;
		delete temp;
	}
}
int peek(Node* &top)
{
	if(top==NULL)
	{
		return -1;
	}
	else
	{
		return top->data;
	}
}
bool isEmpty(Node* &top)
{
	if(top==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void display(Node* &top)
{
	Node *temp=top;
	while(temp!= NULL)
	{
		cout << temp->data << " ";
		temp=temp->next;
	}
	cout << endl;
}
int main()
{
	Node *node1=new Node(22);
	Node *top=node1;
	
	push(top,25);
	push(top,35);
	display(top);
	
	pop(top);
	display(top);
	
	cout << "Top element of the stack is  " << peek(top) << endl;
	cout << "stack empty???  " << isEmpty(top) << endl;
	
	return 0;
}


// Output :-

// 35 25 22 
// Memory freed for data 35
// 25 22 
// Top element of the stack is  25
// stack empty???  0



















// head acts as top
// push implies we have to insert node at starting of LL
// pop implies we have to delete node from starting of LL

class Node {
public:
    int data;
    Node* next;
    int top;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
        top = -1;
    }
};

void push(Node* &top, int data) {
    if(top == NULL) {
        Node* temp = new Node(data);
        top = temp;
    }
    else {
        Node* temp = new Node(data);
        temp -> next = top;
        top = temp;
    }
}

void pop(Node* &top){
    if(top == NULL)
        cout << "Stack underflow" << endl;
    else {
        Node* temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
    }
}

int peek(Node* &top) {
    if(top == NULL) {
        cout << "Stack underflow" << endl;
        return -1;
    }
    else
        return top->data;

}

bool isEmpty(Node* &top) {
    if(top == NULL)
        return true;
    else
        return false;
}


int main() {
    Node* top = NULL;
    
    push(top, 10);
    push(top, 20);
    push(top, 30);

    cout << peek(top) << endl;

    pop(top);

    cout << peek(top) << endl;

    cout << isEmpty(top) << endl;
    
    return 0;
}