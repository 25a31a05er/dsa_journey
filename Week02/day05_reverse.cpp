#include<iostream>
using namespace std;
// CLASS NODE
class node {
public:
    int data;
    node *link;
};
//INSERTION
void insert (node **head, int value) {
    node *t = *head;
    node *cn = new node();
    cn -> data = value;
    cn -> link = NULL;
    if (*head == NULL) {
        *head = cn;
    }
    else {
        while (t->link != NULL) {
            t = t -> link;
        }
        t -> link = cn;
    }
}
//DISPLAY
void display (node *head) {
    cout << "\nLinked List:\n";
    node *t = head;
    while (t != NULL) {
        cout << t -> data << " -> ";
        t = t -> link;
    }
    cout << "NULL\n";
}
//REVERSE
void reverse (node** head) {
	node *prev = NULL, *next = NULL;
    node *curr = *head;
    while (curr != NULL) {
    	next = curr -> link;
        curr -> link = prev;
        prev = curr;  curr = next;
    }
    *head = prev;    
}      
//MAIN Function	
int main() {
    node *h = NULL;
    int val, op;
    
    cout << "NODES\n";
    do {
        cout << "Enter node data: ";
        cin >> val;
        insert (&h, val);
        cout << "Continue? (1/0): ";
        cin >> op;
    } while (op);

    display (h);
    
    cout << "\nReversing:";
    reverse (&h);
    display (h);
    
    return 0;
}
