#include<iostream>
using namespace std;
//Only using pointers

//To print array elements
void printArray (int *p, int n) {
    cout << "Array Elements:" << endl;
    for ( int i=0; i<n; i++) {
        cout << *(p+i) << '\t';
    }
    cout << endl;
}
//To print sum of array
int sumArray (int *p, int n) {
    int sum = 0;
    cout << "Array Sum: ";
    for (int i=0; i<n; i++) {
        sum += *(p+i);
    }
    return sum;
}
//Max element in array
int maxElement (int *p, int n) {
    int max = *p;
    cout << "Max Element: ";
    for (int i=0; i<n; i++) {
        if (max < *(p+i))
            max = *(p+i);
    }
    return max;
}
//Modifying the given array
void updateArray (int *p, int n) {
    for (int i=0; i<n; i++) {
        *(p+i) *= 2;
    }
}
//MainFunction
int main() {
    const int size = 5;
    int arr[size] = {11,22,33,44,55};
    printArray (arr, size);
    cout << endl;
    cout << sumArray (arr, size) << endl
         << endl;
    cout << maxElement (arr, size) << endl
         << endl;
    updateArray (arr, size);
    printArray (arr, size);
    return 0;
}
