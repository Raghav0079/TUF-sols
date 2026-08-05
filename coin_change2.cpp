#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int MOD = 1e9 + 7;

    int count(vector<int>& coins, int N, int amount) {
    
        vector<vector<long long>> dp(N, vector<long long>(amount + 1, 0)); 

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = 1;

        }

        for (int ind = 1; ind < N; ind++) {
            for (int target = 0; target <= amount; target++) {
                int notTaken = dp[ind - 1][target];

                int taken = 0;
                if (coins[ind] <= target)
                    taken = dp[ind][target - coins[ind]];

                dp[ind][target] = (notTaken + taken) % MOD;
            }
        }
        return dp[N - 1][amount];
    }
};



int main() {
   vector<int> coins = {1, 2, 3};
    int amount = 4;
    int N = coins.size(); 
    
    //Create an instance of Solution class
    Solution sol;

    // Print the result
    cout << "The total number of ways is " << sol.count(coins, N, amount) << endl;

    return 0; 
}
