#include<iostream>
using namespace std;

class Student {
	public:
	char name[100];
	int roll;
    float marks;
    
    Student() {}
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

int main()
{
	const int n = 5;
    Student s[n];
    for (int i=0; i<n; i++) {
    	cout << "Student Details " << i+1
        	 << ": " << endl;
        s[i].userInput();   
    }
    //Bubble sort marks
    for (int i=0; i<n-1; i++) {
    	for (int j=0; j<n-i-1; j++) {    
        	if (s[j].marks > s[j+1].marks) {
            	Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        } 
    }
    for (int i=0; i<n; i++) {
    	s[i].display();
    }           
    return 0;
}