class Solution {

    public int editDistance(String start, String target) {
        int n = start.length();  // Length of the start string
        int m = target.length(); // Length of the target string

        int[] prev = new int[m + 1];
        int[] cur = new int[m + 1];


        for (int j = 0; j <= m; j++) {
            prev[j] = j;
        }

        // Calculate edit distances row by row
        for (int i = 1; i <= n; i++) {

            cur[0] = i;
            
            for (int j = 1; j <= m; j++) {
                // If characters match, no additional cost
                if (start.charAt(i - 1) == target.charAt(j - 1)) {
                    cur[j] = prev[j - 1];
                } 
                else {

                    cur[j] = 1 + Math.min(prev[j - 1], Math.min(prev[j], cur[j - 1]));
                }
            }

            System.arraycopy(cur, 0, prev, 0, m + 1);  // Copy cur to prev
        }

        // The value at prev[m] contains the final edit distance
        return prev[m];
    }


}
