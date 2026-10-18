class Solution {
public:
    // Helper function to connect subtrees after deleting a node
    TreeNode* connector(TreeNode* root) {

        if (!root->left)
            return root->right;
        
        else if (!root->right)
            return root->left;

        TreeNode* leftchild = root->left;
        TreeNode* leftmost_child_in_right_subtree = root->right;

        // Traverse to the leftmost node in the right subtree.
        while (leftmost_child_in_right_subtree->left) {
            leftmost_child_in_right_subtree =
                leftmost_child_in_right_subtree->left;
        }

        leftmost_child_in_right_subtree->left = leftchild;

        // Return the right subtree as the new root of the modified tree.
        return root->right;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: if the tree is empty, return NULL.
        if (root == NULL)
            return NULL;

        if (root->data == key) {
            return connector(root);
        }

        // Traverse the tree to find the node to be deleted.
        TreeNode* node = root;
        while (node) {

            if (node->data > key) {
                if (node->left && node->left->data == key) {
                    node->left = connector(node->left);
                    break;
                } else {
                    node = node->left; 
                }
            }
            else {
                if (node->right && node->right->data == key) {
                    node->right = connector(node->right);
                    break;
                } else {
                    node = node->right; 
                }
            }
        }

        // Return the modified tree with the node deleted.
        return root;
    }
};