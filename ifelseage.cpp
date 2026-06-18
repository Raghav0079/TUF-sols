#include <iostream>
using namespace std;

class Solution {
public:

    void isAdult(int age) {
        if (age >= 18) {
            cout << "Adult" << endl;
        } else {
            cout << "Teen" << endl;
        }
    }
};

