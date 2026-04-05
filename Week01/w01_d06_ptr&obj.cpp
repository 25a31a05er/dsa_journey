#include<iostream>
using namespace std;
// Class - attributes + methods
class Student {
	public: // access pointer
	char name[100];
	int roll;
    float marks;
    
    Student() {} // constructor
    void userInput() {
        cin >> name >> roll >> marks;
        cout << endl;
    }    
    void display() {
        cout << "Name: " << name << endl
        	 << "RollNo: " << roll << endl
             << "Marks: " << marks << endl;
        cout << endl;     
	}
};    
//To update student marks
void updateMarks (Student *s, float newMarks) {
    s -> marks = newMarks;
}
// to return stduent with top marks
Student *highestMarks (Student *s, int n) {
	Student *top = s;
    for (int i=1; i<n; i++) {
    	if ((s+i)->marks > top->marks)
        	top = (s+i);
    }
    cout << "Student with highest marks: \n";
    return top;
}            

int main() {
//Variables
	const int n = 5;
    Student sd[n];
    Student *stu = sd;
    int i, op;
    float newMarks;
//To take input and display    
    for (i=0; i<n; i++) {
    	cout << "Student Details " << i+1 << " : ";
        (stu+i) -> userInput();
    }    
    for (i=0; i<n; i++) {
    	cout << "STUDENT " << i+1 << endl;
    	(stu+i) -> display();
    }
// To update marks    
    cout << "Update Marks? (1/0) ";
    cin >> op;
    while (op) {
    	cout << "Student No:? ";
        cin >> i;
        //If student no is out of range
        if (i>n || i<=0) {
        	cout << "Invalid StudentNo." << endl;
       	 cout << "Update Marks? (1/0) ";
    		cin >> op;
            continue;
        }
        //Updating    
        cout << "Current Marks: " 
        	 << (stu+i-1) -> marks;
        cout << endl << "New Marks: ";
        cin >> newMarks;
    	updateMarks ((stu+i-1), newMarks);  
    	(stu+i-1) -> display();
        cout << "Continue? (1/0) ";
        cin >> op;
    }    
    // To display top student
    highestMarks (stu, n) -> display();
    
    return 0;
}