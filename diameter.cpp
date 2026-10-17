// Definition for a binary tree node.
  struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
  };
 

class Solution {
public:
    // Function to find the diameter of a binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        // Initialize the variable to store the diameter of the tree
        int diameter = 0;
        
        // Call the height function to traverse the tree and calculate diameter
        height(root, diameter);
        
        // Return the calculated diameter
        return diameter;
    }

private:
    // Function to calculate the height of the tree and update the diameter
    int height(TreeNode* node, int& diameter) {
        // Base case: If the node is null, return 0 indicating an empty tree height
        if (!node) {
            return 0;
        }

        // Recursively calculate the height of left and right subtrees
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        // Update the diameter with the maximum of current diameter 
        diameter = max(diameter, lh + rh);

        // Return the height of the current node's subtree
        return 1 + max(lh, rh);
    }
};

int main() {
    // Example usage: Create a tree and find its diameter
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int result = solution.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree is: " << result << endl;

    return 0;
}