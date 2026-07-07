#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to compute base^exp manually without using pow()
    int intPower(int base, int exp) {
        int res = 1;
        while (exp--) {
            res *= base;
        }
        return res;
    }

    // Function to check if a number is an Armstrong number
    bool isArmstrong(int n) {
        int original = n;  // Store the original number
        int k = 0, temp = n;

        // Count the number of digits in n
        while (temp > 0) {
            k++;
            temp /= 10;
        }

        int sum = 0;
        temp = n;

        // Compute the sum of k-th power of each digit
        while (temp > 0) {
            int digit = temp % 10;  
            sum += intPower(digit, k);  // Compute digit^k
            temp /= 10;
        }

        // Check if the computed sum matches the original number
        return sum == original;
    }
};