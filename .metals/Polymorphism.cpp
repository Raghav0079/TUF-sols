#include <iostream>
using namespace std;

class ShapeCalculator {

public:
    // Area of Circle
    void area(int radius) {
        double ans = 3.14 * radius * radius;
        cout << "Area of Circle : " << (int)ans << endl;
    }

    // Area of Rectangle
    void area(int length, int width) {
        int ans = length * width;
        cout << "Area of Rectangle : " << ans << endl;
    }

    // Area of Trapezoid
    void area(int base1, int base2, int height) {
        double ans = 0.5 * (base1 + base2) * height;
        cout << "Area of Trapezoid : " << (int)ans << endl;
    }
};


// Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your class `ShapeCalculator`.

It creates an object of class `ShapeCalculator`.
It then calls the `area` method with `radius` as an argument. The method calculates the area of Circle and prints it.
It then calls the `area` method with `length` and `width` as arguments. The method calculates the area of Rectangle and prints it.
It then calls the `area` method with `base1`, `base2`, `height` as arguments. The method calculates the area of Trapezoid and prints it.

int main() {
    int radius, length, width, base1, base2, height;

    cin >> radius >> length >> width >> base1 >> base2 >> height;

    ShapeCalculator sc;
    sc.area(radius);
    sc.area(length, width);
    sc.area(base1, base2, height);

    return 0;
}

*/

/*
// Below are the output statements

cout << "Area of Circle : " << result << endl;
cout << "Area of Rectangle : " << result << endl;
cout << "Area of Trapezoid : " << result << endl;

*/
