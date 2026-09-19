#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
    /**
     * A recursive helper function to generate all combinations
     * of balanced parentheses.
     *
     * @param open The number of open parentheses used so far.
     * @param close The number of close parentheses used so far.
     * @param n The total number of pairs of parentheses.
     * @param s The current string being built.
     * @param ans The vector storing all valid combinations.
     */
    void func(int open, int close, int n, string s, vector<string> &ans) {
        // Base case: if the number of open and close parentheses used
        // is equal to the total number of pairs, add the string to the result.
        if (open == close && (open + close) == 2 * n) {
            ans.push_back(s); 
            return; 
        }
        
        // If the number of open parentheses used is less than the total
        // number of pairs, add an open parenthesis and call the function recursively.
        if (open < n) {
            func(open + 1, close, n, s + '(', ans); 
        }
        
        // If the number of close parentheses used is less than the number
        // of open parentheses, add a close parenthesis and call the function recursively.
        if (close < open) {
            func(open, close + 1, n, s + ')', ans); 
        }
    }
public:
    /**
     * Generates all combinations of n pairs of balanced parentheses.
     *
     * @param n The number of pairs of parentheses.
     * @return A vector containing all valid combinations of parentheses.
     */
    vector<string> generateParenthesis(int n) {
        // Vector to store the result
        vector<string> ans; 
        // Start the recursive generation with initial values
        func(0, 0, n, "", ans); 
        return ans; 
    }
};

int main() {
    Solution sol;
    int n = 3; // Example input
    vector<string> result = sol.generateParenthesis(n);

    cout << "All combinations of balanced parentheses for n = " << n << " are:" << endl;
    for (const string &combination : result) {
        cout << combination << endl;
    }

    return 0;
}
