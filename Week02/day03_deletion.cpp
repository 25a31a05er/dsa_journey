#include<iostream>
using namespace std;
// class node
class node {
public:
    int data;
    node *link;
};
// insert node at ending
void insertNode (node **head, int value) {
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
// delete node at start, at end, at anywhere
void deleteNode (node **h, int value) {
    node *t = *h;
    node *t0 = *h;
    bool status = false;
    
    if (t -> data == value) {
        *h = t -> link;
        t -> link = NULL;
        delete t;
        status = true;
    }
    else {
        while (t -> link != NULL) {
			t = t -> link;
            if (t -> data == value) {
            	t0 -> link = t -> link;
                t -> link = NULL;
                delete t;
                status = true;
                break;
            }
            t0 = t0 -> link;    
        }
    }
    
    if (!status)
        cout << "Element not found.\n";
}
// display linked list
void display (node *head) {
    cout << "\nLinked List:\n";
    node *t = head;
    while (t != NULL) {
        cout << t -> data << " -> ";
        t = t -> link;
    }
    cout << "NULL\n";
}
// main function
int main() {
// variables
    node *h = NULL;
    int val, op;
// to insert
    cout << "Insertion\n";
    do {
        cout << "Enter data: ";
        cin >> val;
        insertNode (&h, val);
        cout << "Continue? (1/0): ";
        cin >> op;
    } while (op);
// to display
    display (h);
// to delete
    cout << "\nDeletion\n";
    do {
        cout << "Delete data: ";
        cin >> val;
        deleteNode (&h, val);
        cout << "Continue? (1/0): ";
        cin >> op;
    } while (op);
// to display
    display (h);
    return 0;
}
