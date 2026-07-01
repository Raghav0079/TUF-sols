const int MOD = 1e9 +7;
 

class Solution {
public:
    int numberOfWays(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;

        vector<int> coins = {1,2,6};
        for(int coin : coins){
            for(int sum = coin ; sum <= n ; sum++){
                dp[sum] = (dp[sum] + dp[sum-coin]) % MOD;
            }

        }
        long long totalWays = 0;
        for(int count4 =0 ; count4<=2 ; count4++){
            int remaining = n - count4 * 4 ;
            if(remaining >= 0){
                totalWays = (totalWays + dp[remaining]) % MOD;
            }
        }
        return (int)totalWays;
        
    }
};