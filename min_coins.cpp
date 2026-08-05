#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    /* Function to find the minimum number 
    of elements needed to form the target sum*/
    int MinimumCoins(vector<int>& coins, int amount) {
        int n = coins.size();
        
        /* Initialize two vectors to store 
        the previous and current DP states*/
        vector<int> prev(amount + 1, 0);
        vector<int> cur(amount + 1, 0);
    
        // Initialize the first row of the DP table
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            // Set it to a very large value if not possible    
            else
            prev[i] = 1e9; 
        }
    
        // Fill the DP table using a bottom-up approach
        for (int ind = 1; ind < n; ind++) {
            
            for (int target = 0; target <= amount; target++) {
                /* Calculate the minimum elements needed
                without taking the current element*/
                int notTake = prev[target];
            
                /* Calculate the minimum elements 
                needed by taking the current element*/
                int take = 1e9; 
                if (coins[ind] <= target)
                    take = 1 + cur[target - coins[ind]];
                
                /* Store the minimum of 'notTake' 
                and 'take' in the current DP state*/
                cur[target] = min(notTake, take);
            }
            /* Update the previous DP state with
            the current state for the next iteration*/
            prev = cur;
        }
    
        // The answer is in the last row of the DP table
        int ans = prev[amount];
    
        /* If 'ans' is still very large, it means 
        it's not possible to form the target sum*/
        if (ans >= 1e9)
            return -1;
        
        // Return the minimum number of coins
        return ans;  
    }
};

int main() {
    vector<int> coins = {1, 2, 3};
    int amount = 7;
    
    //Create an instance of Solution class
    Solution sol;
    
    // Call the function to find the minimum coins
    int result = sol.MinimumCoins(coins, amount);
    
    // Output the result
    cout << "The minimum number of coins required to form the target sum is " << result << endl;
    
    return 0; 
}

