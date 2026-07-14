#include <bits/stdc++.h>
using namespace std;


class College {
private:
    string name;
    string id;

public:
    College(string name, string id) {
        this->name = name;
        this->id = id;
    }

    void displayDetails() {
        cout << "College Name : " << name << endl;
        cout << "College ID : " << id << endl;
    }
};


class University {
private:
    string name;
    vector<College> colleges;

public:
    University(string name) {
        this->name = name;
    }


    void addCollege(string collegeName, string collegeId) {
        colleges.push_back(College(collegeName, collegeId));
    }


    void displayDetails() {
        cout << "University Name : " << name << endl;
        for (College &college : colleges) {
            college.displayDetails();
        }
    }
};

// Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your class `University` and the class `College`.


int main() {

    // Input reading
    string name;
    vector<string> collegeName, collegeId;

    // Creating the object of class University with the name as constructor argument
    University university(name);

    // Adding the college names and IDs using the addCollege method called through the university object
    for (int j = 0; j < collegeName.size(); j++) {
        university.addCollege(collegeName[j], collegeId[j]);
    }

    // Calling the method displayDetails through the university object
    university.displayDetails();

    return 0;
}

*/

/*
// Below is the output format:

cout << "University Name : " << name << endl;
cout << "College Name : " << name << endl;
cout << "College ID : " << id << endl;

*/
