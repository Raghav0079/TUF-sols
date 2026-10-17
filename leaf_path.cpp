#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


class Solution{
public:
    vector<vector<int>> allRootToLeaf(TreeNode* root) {
        vector<vector<int>> allPaths; // Vector to store all root-to-leaf paths
        vector<int> currentPath; // Vector to store the current path
        
        dfs(root, currentPath, allPaths);
        
        return allPaths;
    }


private:
    void dfs(TreeNode* node , vector<int>& path , vector<vector<int>>& allPaths){
        if( !node){
            return;
        }
        path.push_back(node -> data);

        if( !node -> left && !node -> right){
            allPaths.push_back(path);
        } else {
            dfs(node -> left , path , allPaths);
            dfs(node -> right , path , allPaths);
        }
        path.pop_back();
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<vector<int>> paths = solution.allRootToLeaf(root);

    for (const auto& path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}