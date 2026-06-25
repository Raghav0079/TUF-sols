/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    int countNodes(TreeNode* root) { 
        if (root == nullptr) return 0;
        
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        if (lh == rh) return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int findHeightLeft(TreeNode* node) {
        int hght = 0;
        while (node) {
            hght++;
            node = node->left;
        }
        return hght;
    }

    int findHeightRight(TreeNode* node) {
        int hght = 0;
        while (node) {
            hght++;
            node = node->right;
        }
        return hght;
    }
};