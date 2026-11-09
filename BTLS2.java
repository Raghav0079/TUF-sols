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
        longestPath(root);  
        return max_length; 
    }
}
