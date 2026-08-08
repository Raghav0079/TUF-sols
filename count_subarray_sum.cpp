
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(); 
        // Number of subarrays
        int count = 0;

        // starting index
        for (int startIndex = 0; startIndex < n; startIndex++) { 
            int currentSum = 0;
            // ending index
            for (int endIndex = startIndex; endIndex < n; endIndex++) { 
                // calculate the sum of subarray [startIndex...endIndex]
                // sum of [startIndex..endIndex-1] + nums[endIndex]
                currentSum += nums[endIndex];

                // Increase the count if currentSum == k:
                if (currentSum == k)
                    count++;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 1, 2, 4};
    int k = 6;
    // Function call to find the result
    int count = solution.subarraySum(nums, k);
    cout << "The number of subarrays is: " << count << "\n";
    return 0;
}
