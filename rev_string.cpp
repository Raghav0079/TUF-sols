#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to reverse a string
    void reverseString(vector<char>& s) {
        int start = 0, end = s.size()-1;
        
        // Until the string is reversed
        while(start < end) {
            // Swap the characters at start and end
            char ch = s[start];
            s[start] = s[end];
            s[end] = ch;
            
            // Move the pointers towards the center
            start++, end--;
        }
        
        return;
    }
};
