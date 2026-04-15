#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *link;
};

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


void insertAny (node **head, int value, int pos) {
    node *t = *head;
    node *cn = new node();
    cn -> data = value;
    cn -> link = NULL;
    if (*head == NULL) *head = cn;
    else {
        if (pos == 1) {
            cn -> link = t;
            *head = cn;
        }
        else {
        	for (int i=1; i<pos-1; i++) {
            	t = t -> link;
                if (t == NULL) {
                	cout << "Position beyond list.\n";
                    return;
                }    
            }
            cn -> link = t -> link;
            t -> link = cn;    
        }    
    }
}

void display (node *head) {
    cout << "\nLinked List:\n";
    node *t = head;
    while (t != NULL) {
        cout << t -> data << " -> ";
        t = t -> link;
    }
    cout << "NULL\n";
}

int main() {
    node *h = NULL;
    int val, posn, op;
    
    cout << "NODES\n";
    do {
        cout << "Enter node data: ";
        cin >> val;
        insert (&h, val);
        cout << "Continue? (1/0): ";
        cin >> op;
    } while (op);

    display (h);
    
    cout << "\nInsertion\n";
    do {
        cout << "Enter node data: ";
        cin >> val;
        cout << "Enter position: ";
        cin >> posn;
        insertAny (&h, val, posn);
        cout << "Continue? (1/0): ";
        cin >> op;
    } while (op);

    display (h);
    return 0;
}