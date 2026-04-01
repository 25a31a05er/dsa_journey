#include <iostream>
using namespace std;
void swap (int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}
int main() {
//declaring pointer
    int var = 10;
    int *ptr = &var;
    cout << "Val: " << *ptr << endl;
    *ptr = 67;
    cout << "NewVal: " << var << endl;
//pointer arithmetic    
    const int n = 5;
    int arr[n] = {21,22,23,24,25};
    int *parr = arr;
    //int *parr = &arr[0];
    for (int i=0; i<n; i++) {
    	cout << "Num " << i+1 << ": "
             << *(parr + i) << endl;
    }
//swap using pointers
    int a=45, b=56;
    cout << "Before swap: n1,n2 = " << a 
         << ", " << b << endl;
    swap (&a ,&b);
    cout << "After swap: n1,n2 = " << a
         << ", " << b << endl;
    return 0;     
}
