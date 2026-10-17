#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


class Solution{
    vector<vector<int>> result;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if( root == nullptr){
            return result;
        }

    map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> nodesMap;
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while(!q.empty()){
        auto front = q.front();
        q.pop();
        TreeNode* node = front.first;
        int x = front.second.first;
        int y = front.second.second;

        nodesMap[x][y].push(node->data);

        if(node->left){
            q.push({node->left, {x - 1, y + 1}});
        }
        if(node->right){
            q.push({node->right, {x + 1, y + 1}});
        }
    }

    for(auto& xPair : nodesMap){
        vector<int> col;
        for(auto& yPair : xPair.second){
            while(!yPair.second.empty()){
                col.push_back(yPair.second.top());
                yPair.second.pop();
            }
        }
        result.push_back(col);
    }
    return result;
};

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Creating an instance of Solution
    Solution sol;

    // Getting the vertical order traversal
    vector<vector<int>> result = sol.verticalTraversal(root);

    // Printing the result
    cout << "Vertical Order Traversal: " << endl;
    for (const auto& col : result) {
        for (int num : col) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}