#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the number of
       rotations in a rotated sorted array */
    int findKRotation(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        int index = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            
            /* Search space is already sorted
            then nums[low] will always be
            the minimum in that search space */
            if (nums[low] <= nums[high]) {
                if (nums[low] < ans) {
                    index = low;
                    ans = nums[low];
                }
                break;
            }
            // If left part is sorted update the ans
            if (nums[low] <= nums[mid]) {
                if (nums[low] < ans) {
                    index = low;
                    ans = nums[low];
                }
                // Eliminate left half
                low = mid + 1;
            }
            else { 
                /*update the ans if it 
                is less than nums[mid] */
                if (nums[mid] < ans) {
                    index = mid;
                    ans = nums[mid];
                }
                // Eliminate right half
                high = mid - 1;
            }
        }
        //Return the index as answer
        return index;
    }
};

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3}; 
    
    // Create an object of the Solution class
    Solution sol;
    
    int ans = sol.findKRotation(nums);
    
    // Print the result
    cout << "The array is rotated " << ans << " times.\n";
    
    return 0;
}
