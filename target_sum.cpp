#include <bits/stdc++.h>
using namespace std;

class Solution{
    const int mod = (int)1e9 + 7;
private:
    /* Function to count partitions of the 
    array into subsets with a given target sum*/
    int func(vector<int>& num, int target) {
        int n = num.size();

        vector<int> prev(target + 1, 0);

        if (num[0] == 0)
            // 2 cases - pick and not pick
            prev[0] = 2;  
        else
            // 1 case - not pick
            prev[0] = 1;  

        if (num[0] != 0 && num[0] <= target)
            // 1 case - pick
            prev[num[0]] = 1;  

        for (int ind = 1; ind < n; ind++) {
            
            // Initialize current DP state
            vector<int> cur(target + 1, 0);
            for (int tar = 0; tar <= target; tar++) {
                /* Number of ways without 
                taking the current element*/
                int notTaken = prev[tar];

                int taken = 0;
                if (num[ind] <= tar)
                    // Number of ways by taking current element
                    taken = prev[tar - num[ind]];
                
                // Total number of ways for current sum
                cur[tar] = (notTaken + taken) % mod;
            }
            /* Update previous DP state
            for the next iteration*/
            prev = cur;
        }
        // Return the number of ways
        return prev[target];
    }
public:
    /* Function to count the number 
    of ways to achieve the target sum*/
    int targetSum(int n, int target, vector<int>& nums) {
        int totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += nums[i];
        }

        // Checking for edge cases
        if (totSum - target < 0 || (totSum - target) % 2 != 0)
            // Not possible to achieve target sum
            return 0;  

        return func(nums, (totSum - target) / 2);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int target = 3;
    int n = nums.size(); 
    
    //Create an instance of Solution class
    Solution sol;

    // Print the result
    cout << "The total number of ways is " << sol.targetSum(n, target, nums) << endl;

    return 0; 
}

