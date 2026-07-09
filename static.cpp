#include <iostream>
using namespace std;

class Counter {
private:

    static int count;

public:

    Counter() {
        count++;
    }
    static int getCount() {
        return count;
    }

    static void resetCount() {
        count = 0;
    }
};


int Counter::count = 0;