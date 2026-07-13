/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */


class Solution {
public:
    vector<int> toArray(Node *head) {
        Node *current = head;
        while (current->prev) {
            current = current->prev;
        }
        
        vector<int> result;
        while (current) {
            result.push_back(current->val);
            current = current->next;
        }
        return result;
    }
};
