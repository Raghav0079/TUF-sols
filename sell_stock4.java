class Solution {
    // Function to find the maximum profit using tabulation
    private int func(int[] arr, int n, int k) {

        int[][][] dp = new int[n + 1][2][k+1];
        for (int ind = n - 1; ind >= 0; ind--) {
            
            // buy can be 0 (buying) or 1 (selling)
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    // We can buy the stock
                    if (buy == 0) { 
                        dp[ind][buy][cap] = Math.max(0 + dp[ind + 1][0][cap],
                                                     (-1)*arr[ind] + dp[ind + 1][1][cap]);
                    }
                    // We can sell the stock
                    if (buy == 1) { 
                        dp[ind][buy][cap] = Math.max(0 + dp[ind + 1][1][cap],
                                                     arr[ind] + dp[ind + 1][0][cap - 1]);
                    }
                }
            }
        }


        return dp[0][0][k];
    }

    // Function to find the maximum profit
    public int stockBuySell(int[] arr, int n, int k) {
        // Return the answer
        return func(arr, n, k);
    }
}