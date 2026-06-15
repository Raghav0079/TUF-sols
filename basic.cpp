#include<bits/stdc++.h>
using namespace std;

/*
given marks of a student 
grade of the student 
*/
int main() {
    int marks ;
    cin >> marks ;

    if(marks >=90){
        cout << "A";

    }
    else if (marks >= 70){
        cout << "B";

    }
    else if (marks >= 55){
        cout << "C";
    }
    else if(marks >=35){
        cout << "D";
    }
    else{
        cout << "Fail";
    }
    
}
