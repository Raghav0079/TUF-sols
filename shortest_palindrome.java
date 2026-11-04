class Solution {
    // Compute the Longest prefix suffix array for the combined string
    private int[] computeLPS(String s) {
        int n = s.length(); // size of string

        // To store the longest prefix suffix
        int[] LPS = new int[n];

        int i = 1, j = 0;

        // Iterate on the string
        while (i < n) {
            // If the character matches
            if (s.charAt(i) == s.charAt(j)) {
                LPS[i] = j + 1;
                i++;
                j++;
            }

            else {
                // Trace back j pointer till it does not match
                while (j > 0 && s.charAt(i) != s.charAt(j)) {
                    j = LPS[j - 1];
                }

                // If a match is found
                if (s.charAt(i) == s.charAt(j)) {
                    LPS[i] = j + 1;
                    j++;
                }
                i += 1;
            }
        }

        return LPS; // Return the computed LPS array
    }
    

    public String shortestPalindrome(String s) {
        
        // To store the reverse string
        StringBuilder revs = new StringBuilder(s);
        revs.reverse();
        
        // Forming the combined string
        String str = s + "$" + revs;
        
        // Computing the LPS array
        int[] lps = computeLPS(str);
        
        // Calculating the answer
        int ans = s.length() - lps[lps.length - 1];
        
        String toAdd = revs.substring(0, ans);
        
        // Return the result
        return toAdd + s;
    }
}