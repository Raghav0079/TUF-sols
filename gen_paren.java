import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> generateParenthesis(int n) {

        List<String> result = new ArrayList<>();
        // Start the recursive generation with initial values
        backtrack(0, 0, n, "", result);
        return result;
    }

    private void backtrack(int open, int close, int n, String current, List<String> result) {

        // Base case: if the number of open and close parentheses used
        // is equal to the total number of pairs, add the string to the result.
        if (open == close && open + close == 2 * n) {
            result.add(current);
            return;
        }

        // If the number of open parentheses used is less than the total
        // number of pairs, add an open parenthesis and call the function recursively.
        if (open < n) {
            backtrack(open + 1, close, n, current + '(', result);
        }

        // If the number of close parentheses used is less than the number
        // of open parentheses, add a close parenthesis and call the function recursively.
        if (close < open) {
            backtrack(open, close + 1, n, current + ')', result);
        }
    }

    public static void gen_paren(String[] args) {
        Solution sol = new Solution();
        int n = 3; // Example input
        List<String> result = sol.generateParenthesis(n);

        System.out.println("All combinations of balanced parentheses for n = " + n + " are:");
        for (String combination : result) {
            System.out.println(combination);
        }
    }
}