class Solution {
public:
    vector<int> toArray(Node* head) {
        vector<int> result;
        Node* curr = head; // Keep track of the current node
        
        while (curr != nullptr) {
            result.push_back(curr->val);
            curr = curr->next; // Move to the next node
        }
        
        return result;
    }
};