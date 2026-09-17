#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to calculate power of 'x' raised to 'n'
    double power(double x, long long n) {
        // Base case: anything raised to 0 is 1
        if (n == 0) return 1.0;

        // Base case: anything raised to 1 is itself
        if (n == 1) return x;

        // If 'n' is even
        if (n % 2 == 0) {
            // Recursive call: (x * x), n / 2
            return power(x * x, n / 2);
        }
        // If 'n' is odd
        return x * power(x, n - 1);
    }

public:
    // Function to calculate x raised to n
    double myPow(double x, int n) {
        // Convert n to long long to avoid overflow
        long long num = n;

        // If n is negative
        if (num < 0) {
            // Calculate the power of -n and take reciprocal
            return (1.0 / power(x, -num));
        }
        // If n is non-negative
        return power(x, num);
    }
};

int main() {
    Solution sol;
    cout << sol.myPow(2.0, 10) << endl; // Expected: 1024
    return 0;
}
