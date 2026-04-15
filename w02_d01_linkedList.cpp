#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *link;
}; 

int main() {
    node *h = NULL, *cn = NULL, *t = NULL;
    int val, op;
    cout << "NODES\n";
    do {
    	cn = new node();
        cout << "Enter node data: ";
        cin >> val;
        cn -> data = val;
        cn -> link = NULL;
        if (h == NULL) {
        	h = cn;  t = cn;
        }
        else {
        	t -> link = cn;
        	t = cn;
        }    
        cout << "Continue? (1/0): ";
        cin >> op;
    } while (op);      
      
    cout << "\nLinked List:\n";
    t = h;
    while (t != NULL) {
    	cout << t -> data << " -> ";
        t = t -> link;
    }
    cout << "NULL";    
}