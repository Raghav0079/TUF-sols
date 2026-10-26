import java.util.*;

class Solution {
    /* Function to find the longest increasing 
    subsequence in the given array */
    public int LIS(int[] nums) {
        int n = nums.length;
        
        // Arrays for computation
        int[] next = new int[n + 1];
        int[] curr = new int[n + 1];
        
        // Fill the arrays 
        for (int i = n - 1; i >= 0; i--) {
            for (int prevInd = i - 1; prevInd >= -1; prevInd--) {
                // Not Take case
                int notTake = next[prevInd + 1];
                
                // Take case
                int take = 0;
                
                // Check for the Take case
                if (prevInd == -1 || nums[i] > nums[prevInd]) {
                    take = next[i + 1] + 1;
                }
                
                // Store the maximum of the two cases
                curr[prevInd + 1] = Math.max(take, notTake);
            }
            
            next = curr.clone();
        }
        
        // Return the stored result
        return next[0];
    }    
}

class Main {
    public static void main(String[] args) {
        int[] nums = {10, 9, 2, 5, 3, 7, 101, 18};
        
        // Creating an object of Solution class
        Solution sol = new Solution();
        int lengthOfLIS = sol.LIS(nums);
        
        System.out.println("The length of the LIS for the given array is: " + lengthOfLIS);
    }
}