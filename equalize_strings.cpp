#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string initial, string target) {
        // Optimization for faster input/output operations
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        // Store the length of 'initial' and 'target' strings
        int m = initial.size();
        int n = target.size();
        
        // Create a list of indices for each character in 'initial'
        vector<vector<int>> list(26);
        
        // Populate the list with indices of each character
        // in the 'initial' string.
        for (int i = 0; i < m; i++) {
            list[initial[i] - 'a'].push_back(i);
        }
        
        // Variable to track the length of the longest matching
        // substring between 'initial' and 'target'
        int res = 0;
        
        // Iterate through each character in the 'target' string
        for (int i = 0; i < n; i++) {
            
            // For the current character in 'target', iterate
            // through all its occurrences in 'initial'
            for (auto &index : list[target[i] - 'a']) {
                
                // Variable to count the length of the common substring
                int count = 0;
                
                // Compare characters starting from 'index' in 'initial'
                // and 'i' in 'target'
                for (int j = index, k = i; j < m && k < n; j++, k++) {
                    if (initial[j] != target[k])
                        break;  // Stop if characters don't match
                    count++;  // Increment count if characters match
                }
                
                // Update the result with the longest common substring length
                res = max(res, count);
            }
        }
        
        // Return the minimum operations needed to transform 'initial' 
        // into 'target' by removing the unmatched parts from both
        // strings.
        return m + n - 2 * res;
    }
};
