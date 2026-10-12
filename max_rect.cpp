class Solution
{
public:
    int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix){
        if(matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n , vector<int>(m,0));

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            
            // Iterate over each column
            for (int j = 0; j < m; j++) {
                
                // Check if the current cell contains 1
                if (matrix[i][j] == 1) {
                    
                    // Compute consecutive 1s ending at this cell in the current row
                    dp[i][j] = (j == 0) ? 1 : dp[i][j - 1] + 1;
                    
                    // Initialize width as the current consecutive 1s
                    int width = dp[i][j];
                    
                    // Traverse upwards to form rectangles with current cell as bottom-right corner
                    for (int k = i; k >= 0; k--) {
                        
                        // If no 1s at this column in the upper row, break the loop
                        if (dp[k][j] == 0) break;
                        
                        // Update width as the minimum width seen so far
                        width = min(width, dp[k][j]);
                        
                        // Update maximum area using current width and height
                        maxArea = max(maxArea, width * (i - k + 1));
                    }
                }
            }
        }

        return maxArea;
       
    }
};

