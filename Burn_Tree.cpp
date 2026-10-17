#include <bits/stdc++.h>
using namespace std;

// Definition of a binary tree node
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int ans = 0;

    int dfs(TreeNode* node, int start, int& dist) {

        // Return 0 for an empty subtree
        if (!node)
            return 0;

        // Store the distance from the left and right subtree to the start node
        int leftDist = -1;
        int rightDist = -1;

        // Find the height and start-node distance in the left subtree
        int leftHeight = dfs(node->left, start, leftDist);

        // Find the height and start-node distance in the right subtree
        int rightHeight = dfs(node->right, start, rightDist);

        // Check whether the current node is the starting node
        if (node->data == start) {

            // Distance from the starting node to itself is 0
            dist = 0;

            // Fire can spread down both subtrees
            ans = max(ans, max(leftHeight, rightHeight));
        }

        // Check whether the starting node exists in the left subtree
        else if (leftDist != -1) {

            // Distance from the current node to the starting node
            dist = leftDist + 1;

            // Fire can move through the current node into the right subtree
            ans = max(ans, dist + rightHeight);
        }

        // Check whether the starting node exists in the right subtree
        else if (rightDist != -1) {

            // Distance from the current node to the starting node
            dist = rightDist + 1;

            // Fire can move through the current node into the left subtree
            ans = max(ans, dist + leftHeight);
        }

        // Return the height of the current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    int timeToBurnTree(TreeNode* root, int start) {

        // Reset the answer before starting the DFS
        ans = 0;

        // Store the distance from the root to the starting node
        int dist = -1;

        // Perform DFS to calculate the required burning time
        dfs(root, start, dist);

        // Return the maximum time required to burn the tree
        return ans;
    }
};

int main() {

    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Starting node from which the fire begins
    int start = 2;

    // Create the solution object
    Solution sol;

    // Calculate and print the burning time
    cout << sol.timeToBurnTree(root, start) << endl;

    return 0;
}