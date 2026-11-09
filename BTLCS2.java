class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Pair<U, V> {
    public final U first;
    public final V second;
    
    public Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {
    private int max_length = 0;

    private Pair<Integer, Integer> longestPath(TreeNode node) {
        // Base case when node is null
        if (node == null) {
            return new Pair<>(0, 0);  
        }

        int increasing = 1;  
        int decreasing = 1;  
        // Check the left child
        if (node.left != null) {
            Pair<Integer, Integer> left = longestPath(node.left);
            if (node.val == node.left.val + 1) {
                decreasing = left.second + 1;  
            } else if (node.val == node.left.val - 1) {
                increasing = left.first + 1;  
            }
        }
        // Check the Right child
        if (node.right != null) {
            Pair<Integer, Integer> right = longestPath(node.right);
            if (node.val == node.right.val + 1) {
                decreasing = Math.max(decreasing, right.second + 1);  
            } else if (node.val == node.right.val - 1) {
                increasing = Math.max(increasing, right.first + 1); 
            }
        } 
        
        // Update max_length
        max_length = Math.max(max_length, increasing + decreasing - 1); 
        return new Pair<>(increasing, decreasing);  
    }

    public int longestConsecutive(TreeNode root) {
        max_length = 0; // Reset in case solution object is reused
        longestPath(root);  
        return max_length; 
    }
}

public class BTLCS2 {
    public static void main(String[] args) {
        // Test tree:
        //       2
        //      / \
        //     1   3
        TreeNode root = new TreeNode(2);
        root.left = new TreeNode(1);
        root.right = new TreeNode(3);

        Solution sol = new Solution();
        int result = sol.longestConsecutive(root);
        
        System.out.println("Longest Consecutive Path Length: " + result); // Expected output: 3
    }
}