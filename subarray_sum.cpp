/*You are working as an Applied Scientist at Amazon, analyzing the performance of a newly deployed machine learning model used to improve product recommendations.
Over a period of (N) consecutive time intervals, your team records the change in the model's recommendation quality compared to the previous interval. 
A positive value indicates an improvement in performance, while a negative value indicates a decline.
These changes are represented by an integer array (A), where (A_i) denotes the performance change during the (i)-th time interval.

*/

/*Your task is to identify a non-empty contiguous period of time during which the cumulative improvement in the model's performance is maximized - but if interval [i.....j] is selected then cumulative improvement sum is denoted as : -1*a[i] + a[i+1] + ..... + a[j] . 
Also make sure the selected interval size is >=K

*/

/*->smax[i] = maximum subarray sum you can get if the subarray starts at index i 


-> smax[i] = max(a[i] , a[i] + smax[i-1])  


->ans[i] = maximum subarray sum you can get if the subarray starts at index i but definition of subarray has changed 


->ansk[i] = maximum subarray sum you can get if the subarray starts at index i but definition of subarray has changed and size of subarray selected >=k 


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<long long> compute_ansk(const vector<long long>& A, int K) {
    int N = A.size();
    vector<long long> ansk(N, LLONG_MIN);
    
    if (K > N || K <= 0) {
        return ansk;
    }

    // Step 1: Compute prefix sums P
    vector<long long> P(N);
    long long curr_sum = 0;
    for (int i = 0; i < N; ++i) {
        curr_sum += A[i];
        P[i] = curr_sum;
    }

    // Step 2: Compute suffix maximums of P
    // MaxP[x] = max(P[x], P[x+1], ..., P[N-1])
    vector<long long> MaxP(N);
    long long max_val = LLONG_MIN;
    for (int i = N - 1; i >= 0; --i) {
        if (P[i] > max_val) {
            max_val = P[i];
        }
        MaxP[i] = max_val;
    }

    // Step 3: Calculate ansk[i] for each valid starting index i
    for (int i = 0; i < N; ++i) {
        int j_min = i + K - 1;
        if (j_min < N) {
            long long p_prev = (i > 0) ? P[i - 1] : 0;
            long long val_i = 2 * P[i] - p_prev;
            ansk[i] =