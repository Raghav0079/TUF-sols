/*You are given an integer array A of size N. Initially, another array B of size N is filled with all zeros.
Your task is to transform B into A using the minimum number of operations.
You can perform either of the following operations any number of times:
Type 1: Choose any prefix of the array (from index 1 to k) and increase every element in that prefix by 1.
Type 2: Choose any index i and set B[i] directly to any value larger than the current value. 
Determine the minimum number of operations required to obtain the target array A.
Input Format
The first line contains an integer N — the size of the array.
The second line contains N integers A[1], A[2], ..., A[N].
Output Format
Print a single integer — the minimum number of operations required.
Constraints
1<=N<=100000 
1<=A[i]<=10^9 
[2 2 2 1 5] -> “3” 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N);
    for (auto &x : A) cin >> x;

    /*
        dp represents the minimum number of operations needed
        while maintaining the current prefix-increment level.

        We can think of each Type-1 operation as creating one
        "level". Type-2 lets us jump over unwanted levels at
        individual positions.

        For this problem, the optimal number can be computed
        by summing the positive rises, while accounting for
        decreases with Type-2 operations.
    */

    long long ans = 0;
    long long prev = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] > prev) {
            ans += A[i] - prev;
        } else if (A[i] < prev) {
            ans += 1;
        }
        prev = A[i];
    }

    cout << ans << '\n';

    return 0;
}