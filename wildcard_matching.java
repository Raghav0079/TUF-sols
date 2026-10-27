class Solution {
    /* Function to check if 'str' matches 
    'pat' using wildcard pattern matching*/
    public boolean wildCard(String str, String pat) {
        int n = str.length();
        int m = pat.length();

        /* Create two DP rows for 
        tabulation, initialized with false*/
        boolean[] prev = new boolean[n + 1];
        boolean[] curr = new boolean[n + 1];

        // Base Case: empty pattern matches empty string
        prev[0] = true;

        // Base Case: pattern vs empty string
        for (int i = 1; i <= m; i++) {
            curr[0] = (pat.charAt(i - 1) == '*') && prev[0];

            for (int j = 1; j <= n; j++) {
                /* If the characters at the current
                positions match or pat has a '?'*/
                if (pat.charAt(i - 1) == str.charAt(j - 1) || pat.charAt(i - 1) == '?') {
                    curr[j] = prev[j - 1];
                }
                else if (pat.charAt(i - 1) == '*') {
                    /* Two options: either '*' represents an 
                    empty string or it matches a character in str */
                    curr[j] = prev[j] || curr[j - 1];
                }
                else {
                    curr[j] = false;
                }
            }

            // Move current row to previous for next iteration
            prev = curr.clone();
        }

        return prev[n];
    }
}