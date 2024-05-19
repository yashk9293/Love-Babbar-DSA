// Break linked list in two equal circular linked list.

#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node *&head, int d) {
    if (head == NULL) {
        Node *n1 = new Node(d);
        n1->next = n1;
        head = n1;
        return;
    }
    Node *temp = head;
    Node *n1 = new Node(d);
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = n1;
    n1->next = head;
}

void print(Node *&head) {
    Node *temp = head;
    Node *curr = head;
    while (temp->next != curr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
    cout << endl;
}

int getLength(Node *&head) {
    Node *temp = head;
    int count = 1;
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *splitList(Node *&head, int count) {
    Node *temp = head;
    if (count % 2 == 0) {
        int count2 = 1;
        while (count2 < count / 2) {
            temp = temp->next;
            count2++;
        }
        Node *restPart = temp->next;
        Node *restPartNode = restPart;
        temp->next = head;

        count2 = 1;
        while (count2 < count / 2) {
            restPart = restPart->next;
            count2++;
        }
        restPart->next = restPartNode;
        return restPartNode;
    }
    else {
        int count2 = 0;
        while (count2 < count / 2) {
            temp = temp->next;
            count2++;
        }
        Node *restPart = temp->next;
        Node *restPartNode = restPart;
        temp->next = head;

        count2 = 1;
        while (count2 < count / 2) {
            restPart = restPart->next;
            count2++;
        }
        restPart->next = restPartNode;
        return restPartNode;
    }
}

int main() {
    Node *head = NULL;

    insert(head, 12);
    insert(head, 31);
    insert(head, 15);
    insert(head, 1);
    insert(head, 6);
    insert(head, 9);
    insert(head, 17);
    insert(head, 25);

    print(head);

    int count = getLength(head);
    Node *restPart = splitList(head, count);
    print(head);
    print(restPart);

    return 0;
}

// Output :-

// 12 31 15 1 6 9 17 25 
// 12 31 15 1 
// 6 9 17 25 




// OR

void splitCLL(Node *head, Node **head1, Node **head2) {

    Node *slow = head;
    Node *fast = head;

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // After above steps slow is pointing mid and fast is pointing last node
    if (fast->next->next == head) {
        fast = fast->next;
    }
    // Set the head pointer of first half
    *head1 = head;

    // Set the head pointer of second half
    if (head->next != head) {
        *head2 = slow->next;
    }

    // Make second half circular
    fast->next = slow->next;

    // Make first half circular
    slow->next = head;
}






// NOTE: head will be your 1st head, and head2 will be your 2nd head

Node* splitCLL(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    if(head->next == head) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast->next != head) {
        fast = fast->next;
        if(fast->next != head) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    Node* head2 = slow->next;
    fast->next = head2;
    slow->next = head;

    return head2;
}