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
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    Solution solution;
    int result = solution.count(coins, n, amount);
    cout << result << endl;

    return 0;
}

