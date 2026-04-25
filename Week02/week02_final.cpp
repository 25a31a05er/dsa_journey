#include<iostream>
using namespace std;
//class node
class node {
public:
    int data;
    node *link;
};
//insert at the tail
void construct (node **h) {
    int value, ch;
    do {
        node *cn = new node();
        cout << "\nEnter node_data: ";
        cin >> value;
        cn -> data = value;
        cn -> link = NULL;
        if (*h == NULL) *h = cn;
        else {
            node *t = *h;
            while (t -> link != NULL) {
                t = t -> link;
            }
            t -> link = cn;
        }
        cout << "Continue(1/0)? ";
        cin >> ch;
    } while (ch);
}
//display nodes
void display (node *h) {
    node *t = h;
    while (t != NULL) {
        cout << t -> data << " -> ";
        t = t -> link;
    }
    cout << "NULL\n";
}
//search
void search (node *h) {
    int key, op;
    do {
        int pos = 1, c = 0;
        node *t = h;
        cout << "Enter search key: ";
        cin >> key;
        while (t != NULL) {
            if (t -> data == key) {
                c++;
                cout << "Key found at " << pos << endl;
            }
            t = t -> link;
            pos++;
        }
        if (c == 0) cout << "Key not found!\n";
        else cout << "Key found " << c << " times.\n";
        cout << "Continue(1/0) ? ";
        cin >> op;
    } while (op);
}
//insert at any position
void insertNode (node **h) {
    int value, pos, i, ch;
    do {
        node *t = *h;
        node *cn = new node();
        cout << "\nEnter node_data: ";
        cin >> value;
        cn -> data = value;
        cn -> link = NULL;
        cout << "Position to Insert: ";
        cin >> pos;
        if (pos == 1) {
            cn -> link = t;
            *h = cn;
        } else {
            for (int i = 1; i < pos - 1 && t != NULL; i++) {
                t = t->link;
            }
            if (t == NULL) {
                cout << "Position beyond list.\n";
            } else {
                cn->link = t->link;
                t->link = cn;
            }
        }
        cout << "Continue(1/0)? ";
        cin >> ch;
    } while (ch);
}
//deletion
void deleteNode (node **h) {
    int val, op;
    do {
        node *t = *h;
        cout << "\nData to be deleted: ";
        cin >> val;
        if (t -> data == val) {
            *h = t -> link;
            t -> link = NULL;
            delete t;
            cout << "Deleted " << val << endl;
        }
        else {
            while (t->link != NULL && t->link->data != val) {
                t = t->link;
            }
            if (t->link == NULL) {
                cout << "Key not found!\n";
            } else {
                node *t0 = t->link;
                t->link = t0->link;
                t0->link = NULL;
                delete t0;
                cout << "Deleted " << val << endl;
            }
        }
        cout << "Continue(1/0) ? ";
        cin >> op;
    } while (op);
}
//reverse
void reverse (node **h) {
    node *prev = NULL, *curr = *h;
    while (curr != NULL) {
        node *next = curr -> link;
        curr -> link = prev;
        prev = curr;
        curr = next;
    }
    *h = prev;
}
//main function
int main() {
    node *h = NULL;
    cout << "Node Data\n";
    construct (&h);
    cout << "\nLinked List:\n";
    display (h);
    cout << "\nInsert Nodes:\n";
    insertNode (&h);
    cout << "\nUpdated:\n";
    display (h);
    cout << "\nDelete Nodes:\n";
    deleteNode (&h);
    cout << "\nUpdated:\n";
    display (h);
    cout << "\nReversing..\n";
    reverse (&h);
    display (h);
    return 0;
}