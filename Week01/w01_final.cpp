#include<iostream>
using namespace std;

//Student CLASS
class Student {
public:
    char name[20];
    float marks;
    void userInput() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter marks: ";
        cin >> marks;
    }
    void output() {
        cout << name << " " << marks;
        cout << endl;
    }
};

//Display array
void display (Student *s, int n) {
    for (int i=0; i<n; i++) {
        cout << "Student 0" << i+1 << ": ";
        (s + i) -> output();
    }
    cout << endl;
}

//Topper Details
Student *highestMarks (Student *s, int n) {
    Student *top = s;
    for (int i=0; i<n; i++) {
        if ((s+i) -> marks > top -> marks)
            top = s+i;
    }
    return top;
}

//myStrings
int myStrlen (Student *s) {
	char *name = s->name;
	int count = 0;
    while (*name != '\0') {
    	count++;
        name++;
    }
    return count;
}        
void swap (char *a, char *b) {
	char temp = *a;
    *a = *b;
    *b = temp;
}   
char *myStrrev (Student *s) {
    char *name = s -> name;
	int len = myStrlen(s);
    int begin = 0, end = len-1;
    while ( begin < end ) {
        swap (&name[begin], &name[end]);
        begin++;	end--;
    }    
    return name;
}   

//MainFunction
int main() {
	//Inputs
    int n=0, i=0, j=0;
    cout << "Enter size of array: ";
    cin >> n;
    Student arr[n];
    Student *ptr = arr;
    
    //UserInput array
    for (i=0; i<n; i++) {
        cout << "Student " << i+1 << "\n";
        (ptr + i) -> userInput();
        cout << endl;
    }
    
    //Display function
    cout << "\nStudent Details: \n";
    display (ptr, n);
    
    //Bubble sort marks
    for (i=0; i<n; i++) {
        for (j=0; j<n-1-i; j++) {
            if ( (ptr+j)->marks > (ptr+j+1)->marks ) {
                Student temp = *(ptr+j);
                *(ptr+j) = *(ptr+j+1);
                *(ptr+j+1) = temp;
            }
        }
    }
    cout << "\nSorted Details: \n";
    display (ptr, n);
    
    //Highest marks
    cout << "Topper: ";
    Student *top = highestMarks (ptr, n);
    top -> output();
    
    //Reverse topper name
    cout << "Reverse: " << myStrrev (top);

    return 0;
}