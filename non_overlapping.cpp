#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Comparator function to compare intervals based on their ending times
    bool static comp(vector<int>& val1, vector<int>& val2) {
        return val1[1] < val2[1];
    }
    
public:
    // Function to count the maximum number of non-overlapping intervals
    int MaximumNonOverlappingIntervals(vector<vector<int>>& intervals) {
        // Sort the intervals based on their ending times
        sort(intervals.begin(), intervals.end(), comp);
        
        // Get total number of intervals
        int n = intervals.size();
        
        // Initialize counter
        int cnt = 1;
        
        // Keep track of the ending time
        int lastEndTime = intervals[0][1];
        
        // Iterate through all intervals
        for (int i = 1; i < n; i++) {
            /* Check if the starting time of the current 
            interval is greater than or equal to 
            the ending time of the last 
            selected interval */
            if (intervals[i][0] >= lastEndTime) {
                // Increment counter
                cnt++;
                // Update the ending time
                lastEndTime = intervals[i][1];
            }
        }
        return n - cnt;
    }

};

// Main function
int main() {
    vector<vector<int>> intervals = {{0, 5}, {3, 4}, {1, 2}, {5, 9}, {7, 9}};
    
    // Creating an object of solution class
    Solution solution;
    
    // Function call to get the maximum non-overlapping intervals
    int ans = solution.MaximumNonOverlappingIntervals(intervals);
    
    cout << "Maximum Non-Overlapping Intervals: " << ans << endl;
    
    return 0;
}