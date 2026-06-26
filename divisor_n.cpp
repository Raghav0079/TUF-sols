#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> smallDivisors;
        vector<int> largeDivisors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                smallDivisors.push_back(i);
                if (i != n / i) {
                    largeDivisors.push_back(n / i);
                }
            }
        }
        for (int i = largeDivisors.size() - 1; i >= 0; i--) {
            smallDivisors.push_back(largeDivisors[i]);
        }

        return smallDivisors;
    }
};