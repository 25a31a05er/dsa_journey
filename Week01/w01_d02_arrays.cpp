#include<iostream>
using namespace std;

int main() {
//Array declaration
    const int n = 5;
    int a[n], i;
    for (i=0; i<n; i++) {
    	cout << "Element " << i+1 << ": ";
        cin >> a[i];
        cout << endl;
    }
    cout << "Array elements: ";
    for (i=0; i<n; i++) {
        cout << a[i] << ", ";
    }cout << endl;
    
    cout << endl;
    
//Max and min of an array
    int min = a[0], max = a[0];
    for (i=0; i<n; i++) {
        if (a[i] < min)  	   min = a[i]; 
        else if (a[i] > max)	max = a[i]; 
    }
    cout << "Min: " << min << "\t" << "Max: " 
    	 << max << endl;
    
    cout << endl; 
    
//Reverse array
    for (i=0; i<n/2; i++) {
        int temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }
    cout << "Reversed Array: ";      
    for (i=0; i<n; i++) {
        cout << a[i] << ", ";
    } cout << endl;
    
    cout << endl;
    
//Linear Search
    int key;
    cout << "Enter search key: ";
    cin >> key;
    bool status = false;
    for (i=0; i<n; i++) {
        if (a[i] == key) {
            cout <<"Key found at "<<i+1<<endl;
            status = true;
        }
    }
    if (status != true) cout<<"Key not found!";
    cout << endl;    
    
    return 0;     
}