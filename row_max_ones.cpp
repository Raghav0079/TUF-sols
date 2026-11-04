#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the row with the maximum number of 1s.
    int rowWithMax1s(vector<vector<int>>& mat) {
        // Store the number of rows and columns in the matrix.
        int n = mat.size();
        int m = mat[0].size();

        // Start from the top-right corner of the matrix.
        int row = 0;
        int col = m - 1;
        int ans = -1;

        // Traverse the matrix by moving left or down.
        while (row < n && col >= 0) {
            // If the current element is 1, move left to find more 1s.
            if (mat[row][col] == 1) {
                ans = row;
                col--;
            }
            // If the current element is 0, move down to the next row.
            else {
                row++;
            }
        }

        // Return the row index with the maximum number of 1s.
        return ans;
    }
};

int main() {
    // Create a row-wise sorted binary matrix.
    vector<vector<int>> matrix = {
        {0, 0, 1},
        {0, 1, 1},
        {0, 1, 1}
    };

    // Create an instance of the Solution class.
    Solution sol;

    // Print the answer.
    cout << "The row with maximum number of 1's is: "
         << sol.rowWithMax1s(matrix) << '\n';

    return 0;
}