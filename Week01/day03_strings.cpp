#include<iostream>
using namespace std; 
//strlen not using string.h
int myStrlen(char *s) {
    int count = 0;
    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
}
//strcpy not using string.h
char *myStrcpy (char *dest, char *src) {
    char *start = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return start;
}    
//strrev not using string.h
void swap (char *a, char *b) {
	char temp = *a;
    *a = *b;
    *b = temp;
}    
char *myStrrev (char *s) {
    char *initial = s;
	int len = myStrlen(s);
    int begin = 0, end = len-1;
    while ( begin < end ) {
        swap ( &s[begin], &s[end] );
        begin++;	end--;
    }    
    return initial;
}
//Display output
int main()
{
    char str[] = "APRIL";
    
    cout << "Length: " << myStrlen(str) << endl;
    char cpy[10];
    cout << "Copy: " << myStrcpy(cpy,str) << endl; 
    cout << "Reverse: " << myStrrev(str) << endl;
    
    if ( myStrcpy(cpy,str) == myStrrev(str) ) 
        cout << "YES! A Palindrome.";
    else cout << "Not a palindrome.";
    
    cout << endl;
    return 0;
}
