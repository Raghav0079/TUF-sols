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

int main() {
    // Hardcoded inputs
    int radius = 2;
    int length = 2;
    int width = 3;
    int base1 = 2;
    int base2 = 3;
    int height = 2;

    // Create object and call overloaded methods
    ShapeCalculator calc;
    calc.area(radius);
    calc.area(length, width);
    calc.area(base1, base2, height);

    return 0;
}