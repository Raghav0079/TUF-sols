class Solution {
public:
    vector<int> setDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i = 0, n = nums1.size();
        int j = 0, m = nums2.size();
        
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                // nums1[i] is smaller, so it's not present in nums2
                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                i++;
            } else if (nums2[j] < nums1[i]) {
                // nums2[j] is smaller, so it's not present in nums1
                if (result.empty() || result.back() != nums2[j]) {
                    result.push_back(nums2[j]);
                }
                j++;
            } else {
                // Elements match; skip this value entirely in both arrays
                int common_val = nums1[i];
                while (i < n && nums1[i] == common_val) i++;
                while (j < m && nums2[j] == common_val) j++;
            }
        }
        
        // Append remaining elements from nums1
        while (i < n) {
            if (result.empty() || result.back() != nums1[i]) {
                result.push_back(nums1[i]);
            }
            i++;
        }
        
        // Append remaining elements from nums2
        while (j < m) {
            if (result.empty() || result.back() != nums2[j]) {
                result.push_back(nums2[j]);
            }
            j++;
        }
        
        return result;
    }
};
