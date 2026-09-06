#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    /* Function to calculate the number of gas 
    stations required for given distance*/
    int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
        // Size of the array
        int n = arr.size(); 
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            
            /* Calculate number of gas stations
            needed between two points*/
            int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
            
            // Adjust if exact distance fits perfectly
            if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
                numberInBetween--;
            }
            
            cnt += numberInBetween;
        }
        return cnt;
    }
public:
    /* Function to minimize the maximum
    distance between gas stations*/
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size(); 
        long double low = 0;
        long double high = 0;

        /* Find the maximum distance between
        consecutive gas stations*/
        for (int i = 0; i < n - 1; i++) {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }

        /* Apply Binary search to find the 
        minimum possible maximum distance*/
        long double diff = 1e-6;
        while (high - low > diff) {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, arr);

            /* Adjust the search range based on 
            the number of gas stations required*/
            if (cnt > k) {
                low = mid;
            } else {
                high = mid;
            }
        }

        // Return the smallest maximum distance found
        return high;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;

    // Create an instance of the Solution class
    Solution sol;

    // Call the minimiseMaxDistance method and print the result
    long double ans = sol.minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";

    return 0;
}