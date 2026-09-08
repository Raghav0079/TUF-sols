#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            
            high = mid - 1;
        }
        else {
            low = mid + 1; 
        }
    }

    return ans;
}
public:

    int rowWithMax1s(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int cnt_max = 0; 
        
        int index = -1;  

        for (int i = 0; i < n; i++) {
            // Get the number of 1's
            int cnt_ones = m - lowerBound(mat[i], m, 1);
            
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }

        return index;
    }
};


int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    
    // Create an instance of the Solution class
    Solution sol; 
    
    // Print the answer
    cout << "The row with maximum number of 1's is: " <<
            sol.rowWithMax1s(matrix) << '\n';

    return 0;
}