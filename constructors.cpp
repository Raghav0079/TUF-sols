#include <bits/stdc++.h>
using namespace std;

class Rectangle {
private:
    double length;
    double width;
    double area;

public:
    // Default constructor
    Rectangle() {
        this->length = 1.0;
        this->width = 1.0;
        this->area = 1.0;
    }

    // Parameterized constructor
    Rectangle(double length, double width) {
        this->length = length;
        this->width = width;
        this->area = 0.0;
    }

    // Method to calculate the area of the rectangle
    void calculateArea() {
        this->area = this->length * this->width;
    }

    // Method to display the details of the rectangle
    void displayDetails() {
        cout << fixed << setprecision(2);
        cout << "Length : " << this->length << endl;
        cout << "Width : " << this->width << endl;
        cout << "Area : " << this->area << endl;
    }
};