#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to find the maximum element in the vector 
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        int n = v.size();
        
        // Find the maximum element
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    /* Helper function to calculate total hours
    required at given hourly rate */
    long long calculateTotalHours(vector<int> &v, int hourly) {
        long long totalH = 0;
        int n = v.size();
        
        // Calculate total hours required
        for (int i = 0; i < n; i++) {
            totalH += ceil((double)(v[i]) / (double)(hourly));
        }
        return totalH;
    }

public:
    // Function to find the minimum rate to eat bananas 
    int minimumRateToEatBananas(vector<int> nums, int h) {
        // Find the maximum number of bananas
        int maxi = findMax(nums);

        /* Find the minimum value of k
        that satisfies the condition*/
        for (int i = 1; i <= maxi; i++) {
            long long reqTime = calculateTotalHours(nums, i);
            if (reqTime <= (long long)h) {
                return i;
            }
        }

        /* Dummy return statement (should 
        not be reached in valid cases)*/
        return maxi;
    }
};

int main() {
    vector<int> v = {7, 15, 6, 3};
    int h = 8;

    // Create an object of the Solution class
    Solution sol;

    int ans = sol.minimumRateToEatBananas(v, h);

    // Print the result
    cout << "Koko should eat at least " << ans << " bananas/hr.\n";

    return 0;
}
