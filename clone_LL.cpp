#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode *random;
    ListNode() {
        val = 0;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* r) {
        val = data1;
        next = next1;
        random = r;
    }
};

class Solution {
public:
    // Insert a copy of each node in between the original nodes
    void insertCopyInBetween(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* nextElement = temp->next;
            // Create a new node with the same data
            ListNode* copy = new ListNode(temp->val);
            
            copy->next = nextElement;
            
            temp->next = copy;
            
            temp = nextElement;
        }
    }

    // Function to connect random pointers of the copied nodes
    void connectRandomPointers(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL) {
            // Access the copied node
            ListNode* copyNode = temp->next;
            
            if (temp->random) {
                
                copyNode->random = temp->random->next;
            } else {
                
                copyNode->random = NULL;
            }
            
            // Move to next original node
            temp = temp->next->next;
        }
    }

    // Function to retrieve the deep copy of the linked list
    ListNode* getDeepCopyList(ListNode* head) {
        ListNode* temp = head;
        // Create a dummy node
        ListNode* dummyNode = new ListNode(-1);
        // Initialize a result pointer
        ListNode* res = dummyNode;

        while (temp != NULL) {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        
        return dummyNode->next;
    }

    // Function to clone the linked list
    ListNode* copyRandomList(ListNode* head){
        if (!head) return nullptr;
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};


void printClonedLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << "Data: " << head->val;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->val;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
        head = head->next;
    }
}

int main() {
    // Example linked list: 7 -> 14 -> 21 -> 28
    ListNode* head = new ListNode(7);
    head->next = new ListNode(14);
    head->next->next = new ListNode(21);
    head->next->next->next = new ListNode(28);

    // Assigning random pointers
    head->random = head->next->next; // 7 -> 21
    head->next->random = head; // 14 -> 7
    head->next->next->random = head->next->next->next; // 21 -> 28
    head->next->next->next->random = head->next; // 28 -> 14

    // Print the original linked list
    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    
    Solution solution;
    ListNode* clonedList = solution.copyRandomList(head);
    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}