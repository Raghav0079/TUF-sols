import java.util.*;

class Solution {
    // Function to find the upper bound of an element in a sorted row
    private int upperBound(int[] arr, int x, int m) {
        int low = 0, high = m - 1;
        int ans = m;

        // Apply binary search
        while (low <= high) {
            int mid = (low + high) / 2;

            // If arr[mid] > x, it can be a possible upper bound
            if (arr[mid] > x) {
                ans = mid;
                // Look for a smaller upper bound on the left
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    // Function to count how many elements in the matrix are less than or equal to x
    private int countSmallEqual(int[][] matrix, int n, int m, int x) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upperBound(matrix[i], x, m);
        }
        return cnt;
    }

    // Function to find the median element in the matrix
    public int findMedian(int[][] matrix) {
        int n = matrix.length; // Number of rows
        int m = matrix[0].length; // Number of columns

        int low = Integer.MAX_VALUE, high = Integer.MIN_VALUE;

        // Initialize low and high
        for (int i = 0; i < n; i++) {
            low = Math.min(low, matrix[i][0]);
            high = Math.max(high, matrix[i][m - 1]);
        }

        int req = (n * m) / 2;

        // Perform binary search to find the median
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int smallEqual = countSmallEqual(matrix, n, m, mid);

            if (smallEqual <= req) low = mid + 1;
            else high = mid - 1;
        }

        return low;
    }
}

public class Main1 {
    public static void main(String[] args) {
        int[][] matrix = {
            {1, 2, 3, 4, 5},
            {8, 9, 11, 12, 13},
            {21, 23, 25, 27, 29}
        };

        Solution sol = new Solution();

        int result = sol.findMedian(matrix);
        System.out.println("The median element is: " + result);
    }
}