class Solution {
private int func(int i , int j , int[][] matrix , int[][] dp){
    if( i < 0 || j < 0 || matrix[i][j] == 1) return 0;
    else if ( i==0 && j ==0) return 1;

    if (dp[i][j] != -1) return dp[i][j];
    int up = func(i - 1, j, matrix, dp);
    int left = func(i, j - 1, matrix, dp);

    return dp[i][j] = up + left;
}

public int uniquePathsWithObstacles(int[][] matrix){
    int m = matrix.length;
    int n = matrix[0].length;

    int[][] dp = new int [m][n];
    for (int[] row : dp) Arrays.fill(row , -1);

    return func(m-1 , n-1 , matrix , dp);
}
}
