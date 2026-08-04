class Solution{
    int modulo = 1e9+7;
public:
	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(K + 1, 0));

        for(int i=0 ; i < n ; i++){
            dp[i][0] = 1;
        }

        if (arr[0] <= K) {
            dp[0][arr[0]] = 1;
        }


        for(int ind=1 ; ind < n ; ind++){
            for(int target =1 ; target <=K ; target++){
                int notTaken = dp[ind - 1][target];

                int taken = 0 ;

                if(arr[ind] <= target){
                    taken = (dp[ind-1][target - arr[ind]]) % modulo ;
                }

                dp[ind][target] = (notTaken + taken) % modulo;
            }
        }

        return dp[n-1][K];
	}
};