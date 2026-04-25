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

void displayLL (node *head) {
    cout << "\nLinked List:\n";
    node *t = head;
    while (t != NULL) {
        cout << t -> data << " -> ";
        t = t -> link;
    }
    cout << "NULL";
}

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

    displayLL (h);
    return 0;
}
