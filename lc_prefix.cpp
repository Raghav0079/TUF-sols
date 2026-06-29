#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Method to find the longest common prefix in a vector of strings
    string longestCommonPrefix(vector<string>& str) {
        // Edge case: empty vector
        if (str.empty()) return "";
        
        // Sort the vector to get the lexicographically smallest and largest strings
        sort(str.begin(), str.end());
        // First string (smallest in sorted order)
        string first = str[0]; 
        // Last string (largest in sorted order)
        string last = str[str.size() - 1]; 
        
        // Compare characters of the first and last strings
        int minLength = min(first.size(), last.size());
        string ans = "";
        for (int i = 0; i < minLength; i++) {
            // If characters don't match, return the current prefix
            if (first[i] != last[i]) {
                return ans;
            }
            // Append the matching character to the result
            ans += first[i];
        }
        
        // Return the longest common prefix found
        return ans;
    }
};
