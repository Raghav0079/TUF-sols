#include <vector>

using namespace std;

class Solution {
private:
    long long mergeAndCount(vector<int>& nums, int low, int mid, int high, int k) {
        long long count = 0;
        int j = mid + 1;

        // Count pairs satisfying the condition: nums[i] + k < nums[j]
        for (int i = low; i <= mid; i++) {
            // Convert to long long to prevent integer overflow during addition
            while (j <= high && (long long)nums[i] + k >= nums[j]) {
                j++;
            }
            // All elements from index j to high in the right array match the condition
            count += (high - j + 1);
        }

        // Standard merge process to sort the array
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return count;
    }

    long long mergeSort(vector<int>& nums, int low, int high, int k) {
        if (low >= high) return 0;
        
        int mid = low + (high - low) / 2;
        long long count = 0;

        count += mergeSort(nums, low, mid, k);
        count += mergeSort(nums, mid + 1, high, k);
        count += mergeAndCount(nums, low, mid, high, k);

        return count;
    }

public:

    int NumberOfJumps(vector<int>& nums, int k) {
        return mergeSort(nums, 0, nums.size() - 1, k);
    }
};
