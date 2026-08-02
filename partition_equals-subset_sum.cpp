class Solution{
private:
    /* Function to check if it's possible to partition
    the array into two subsets with equal sum*/
    bool func(int n, vector<int> &arr) {
        int totSum = 0;

        // Calculate the total sum of the array
        for (int i = 0; i < n; i++) {
            totSum += arr[i];
        }

        /* If the total sum is odd, it cannot
        be partitioned into two equal subsets*/
        if (totSum % 2 == 1)
            return false;
        else {
            int k = totSum / 2;

            /* Create a vector to represent 
            the previous row of the DP table*/
            vector<bool> prev(k + 1, false);

            /* Base case: If the target sum is 0, it can
            be achieved by not selecting any elements*/
            prev[0] = true;

            /* Initialize the first row based 
            on the first element of the array*/
            if (arr[0] <= k)
                prev[arr[0]] = true;

            /* Fill in the DP table
            using a bottom-up approach*/
            for (int ind = 1; ind < n; ind++) {
                /* Initialize a vector to represent 
                the current row of the DP table*/
                vector<bool> cur(k + 1, false);
                cur[0] = true;

                for (int target = 1; target <= k; target++) {
                    // Exclude the current element
                    bool notTaken = prev[target];

                    /* Include the current element 
                    if it doesn't exceed the target*/
                    bool taken = false;
                    if (arr[ind] <= target)
                        taken = prev[target - arr[ind]];

                    // Update the current row of the DP table
                    cur[target] = notTaken || taken;
                }

                /* Set the current row as the 
                previous row for the next iteration*/
                prev = cur;
            }
            /* The final result is in the last cell
            of the previous row of the DP table*/
            return prev[k];
        }
    }
public:
    /* Function to check if the array can
    be partitioned into two equal subsets*/
    bool equalPartition(int n, vector<int>& arr) {
            
        // Return the result
        return func(n, arr);
    }
};