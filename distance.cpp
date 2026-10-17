class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        // Step 1: Create a map to store the parent of each node
        Map<TreeNode, TreeNode> parentMap = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            // If the left child exists, map its parent and push it into the queue
            if (node.left != null) {
                parentMap.put(node.left, node);
                queue.add(node.left);
            }
            // If the right child exists, map its parent and push it into the queue
            if (node.right != null) {
                parentMap.put(node.right, node);
                queue.add(node.right);
            }
        }

        // Step 2: Use BFS to find all nodes at distance k from the target
        List<Integer> result = new ArrayList<>();
        Set<TreeNode> visited = new HashSet<>();
        queue.add(target);
        visited.add(target);
        int currentDistance = 0;

        // Continue BFS until the desired distance is reached
        while (!queue.isEmpty()) {
            if (currentDistance == k) {
                // Collect all nodes at distance k
                while (!queue.isEmpty()) {
                    result.add(queue.poll().data);
                }
                return result;
            }
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                // Check left child
                if (node.left != null && !visited.contains(node.left)) {
                    queue.add(node.left);
                    visited.add(node.left);
                }
                // Check right child
                if (node.right != null && !visited.contains(node.right)) {
                    queue.add(node.right);
                    visited.add(node.right);
                }
                // Check parent
                if (parentMap.containsKey(node) && !visited.contains(parentMap.get(node))) {
                    queue.add(parentMap.get(node));
                    visited.add(parentMap.get(node));
                }
            }
            currentDistance++;
        }

        return result;
    }
}