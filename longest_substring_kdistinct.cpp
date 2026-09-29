#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the maximum length of 
    substring with at most k distinct characters */
    int kDistinctChar(string& s, int k) {
        
        // Length of the input string
        int n = s.size();  
        
        /* Variable to store the 
        maximum length of substring*/
        int maxLen = 0;  
        
        /* Map to track the count of each
        character in the current window*/
        unordered_map<char, int> mpp;
        
        // Pointers for the sliding window approach
        int l = 0, r = 0;
        
        while(r < n){
            mpp[s[r]]++;
            
            /* If number of different characters exceeds
             k, shrink the window from the left*/
            if(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            
            /* If number of different characters 
            is at most k, update maxLen*/
            if(mpp.size() <= k){
                maxLen = max(maxLen, r - l + 1);
            }
            
            r++;
        }
        
        // Return the maximum length
        return maxLen;
    }
};

int main() {
    string s = "aaabbccd";  
    int k = 2;
    
    // Create an instance of Solution class
    Solution sol;
    
    int length = sol.kDistinctChar(s, k);
    
    // Print the result
    cout << "Maximum length of substring with at most " << k << " distinct characters: " << length << endl;
    
    return 0;
}