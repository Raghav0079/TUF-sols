#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Modulus value to avoid overflow in calculations.
    int mod = (int)1e9 + 7;

private:
    /* Function to calculate the number of subsets
       with a specific target sum. Uses space optimization
       to store only the previous state in the DP table. */
    int findWays(vector<int> &num, int tar) {
        int n = num.size();
        
        /* DP table to store number of ways
        to achieve a certain target sum.*/
        vector<int> prev(tar + 1, 0);
        
        /* 2 cases for target 0 when the first 
        element is 0: either pick it or not.*/
        if (num[0] == 0) prev[0] = 2;  
        /* 1 case for target 0 when the first
        element is non-zero: just don't pick it.*/
        else prev[0] = 1;  

        /* Initialize the base case for the
        first element and non-zero target.*/
        if (num[0] != 0 && num[0] <= tar) prev[num[0]] = 1;  

        /* Iterate through all elements of the 
        array starting from the second element.*/
        for (int ind = 1; ind < n; ind++) {
            
            vector<int> cur(tar + 1, 0); 
            for (int target = 0; target <= tar; target++) {
                /* Number of ways to achieve the target 
                sum without including the current element.*/
                int notTaken = prev[target];
                
                /* Number of ways to achieve the target sum 
                by including the current element.*/
                int taken = 0;
                if (num[ind] <= target)
                    taken = prev[target - num[ind]];
                
                /* Total ways to achieve the target sum either
                including or excluding the current element.*/
                cur[target] = (notTaken + taken) % mod;
            }
            /* Update the previous state to the current
            state for the next iteration.*/
            prev = cur;
        }
        // Return the number of subsets
        return prev[tar];
    }

public:
    /* Function to count the number of subsets with a 
    given difference.Uses the helper function findWays
    to find number of subsets with a specific target sum. */
    int countPartitions(int n, int diff, vector<int>& arr) {
        int totSum = 0;
        // Calculate the total sum of elements in the array.
        for (int i = 0; i < n; i++) {
            totSum += arr[i];
        }
        
        /* If the total sum minus the difference is negative
        or odd, it's not possible to partition the array
        into subsets with the given difference.*/
        if (totSum - diff < 0 || (totSum - diff) % 2) return 0;
        
        // Calculate the target sum for one subset.
        return findWays(arr, (totSum - diff) / 2);
    }
};
