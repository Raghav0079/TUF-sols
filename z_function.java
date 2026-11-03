import java.util.*;

class Solution {

    // Compute the Z array for the combined string
    private int[] computeZarray(String s) {
        int n = s.length(); // size of string

        int[] Z = new int[n]; // Z-array

        // Pointers to mark the window
        int left = 0, right = 0;

        // For every character
        for(int i = 1; i < n; i++) {

            // Out of window
            if(i > right) {
                while(i + Z[i] < n && s.charAt(i + Z[i]) == s.charAt(Z[i])) {
                    Z[i]++;
                }
            }

            // Else (Inside the window)
            else {
                // Check for inside
                if(i + Z[i - left] <= right) {
                    Z[i] = Z[i - left];
                }

                // Else compute again using brute force method
                else {
                    Z[i] = right - i + 1; // Take the answer till boundary

                    // Start matching beyond boundary using brute force
                    while(i + Z[i] < n && s.charAt(i + Z[i]) == s.charAt(Z[i])) {
                        Z[i]++;
                    }
                }
            }

            // Update the window only if it extends beyond current boundary
            if(i + Z[i] - 1 > right) {
                left = i;
                right = i + Z[i] - 1;
            }
        }

        return Z; // Return the computed Z-array
    }

    // Function to find all indices of pattern in text
    public List<Integer> search(String text, String pattern) {
        String s = pattern + '$' + text; // Combined string

        // Function call to find the Z array for the combined string
        int[] Z = computeZarray(s);

        // Length of pattern and text
        int n = text.length(), m = pattern.length();

        // To store the result
        List<Integer> ans = new ArrayList<>();

        // Iterate on the combined string after the delimiter
        for(int i = m+1; i < s.length(); i++) {
            if(Z[i] == m) {
                ans.add(i - (m + 1));
            }
        }

        return ans;
    }
}

class Main {
    public static void main(String[] args) {
        String text = "xyzabxyzabxyz";
        String pattern = "xyz";

        // Creating an instance of the solution class
        Solution sol = new Solution();

        // Function call to find all indices of pattern in text
        List<Integer> ans = sol.search(text, pattern);

        for(int ind : ans) {
            System.out.print(ind + " ");
        }
    }
}