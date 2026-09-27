#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*  Function to search for the target element 
        in a rotated sorted array with duplicates   */
    bool searchInARotatedSortedArrayII(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0, high = n - 1;
        
        // Applying binary search algorithm 
        while (low <= high) {
            int mid = (low + high) / 2;

            // Check if mid points to the target
            if (nums[mid] == k) return true;

            // Handle duplicates: if nums[low], nums[mid], and nums[high] are equal
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low = low + 1;
                high = high - 1;
                continue;
            }

            // Check if the left part is sorted
            if (nums[low] <= nums[mid]) {
                /*  Eliminate the right part if target
                    exists in the left sorted part */
                if (nums[low] <= k && k <= nums[mid]) {
                    high = mid - 1;
                } 
                // Otherwise eliminate the left part
                else {
                    low = mid + 1;
                }
            } else {
                /*  If the right part is sorted and
                    k exists in the right sorted
                    part, eliminate the left part   */
                if (nums[mid] <= k && k <= nums[high]) {
                    low = mid + 1;
                } 
                // Otherwise eliminate the right part
                else {
                    high = mid - 1;
                }
            }
        }
        // If k is not found
        return false;
    }
};

int main() {
    vector<int> nums = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3; 

    // Create an instance of the Solution class
    Solution sol;

    // Function call to search for the target element
    bool result = sol.searchInARotatedSortedArrayII(nums, k);

    if (!result)
        cout << "k is not present.\n";
    else
        cout << "k is present in the array.\n";

    return 0;
}