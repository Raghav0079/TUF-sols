class Solution {
public:
/* Function to find two indices in the array `nums`
       such that their elements sum up to `target`.
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // Map to store (element, index) pairs
        unordered_map<int, int> mpp; 
        
        // Size of the nums vector
        int n = nums.size(); 

        for (int i = 0; i < n; i++) {
             // Current number in the vector
            int num = nums[i];
             // Number needed to reach the target
            int moreNeeded = target - num;

            // Check if the complement exists in map
            if (mpp.find(moreNeeded) != mpp.end()) {
                /* Return the indices of the 
                two numbers that sum up to target*/
                return {mpp[moreNeeded], i};
            }

            // Store current number and its index in map
            mpp[num] = i;
        }

        return {-1, -1};
    }
};