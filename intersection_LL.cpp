#include <iostream>
#include <unordered_set>

using namespace std;

// Definition of singly linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() {
        val = 0;
        next = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1) {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    // Function to find the intersection node of two linked lists
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Create a hash set to store the nodes 
        //Of the first list
        unordered_set<ListNode*> nodes_set;
        
        //Traverse the first linked list 
        //And add all its nodes to the set
        while (headA != NULL) {
            nodes_set.insert(headA);
            headA = headA->next;
        }

        //Traverse the second linked list 
        //And check for intersection
        while (headB != NULL) {
            // If a node from the second list is found in the set,
            // It means there is an intersection
            if (nodes_set.find(headB) != nodes_set.end()) {
                return headB;
            }
            headB = headB->next;
        }

        // No intersection found, return NULL
        return NULL;
    }
};

// Utility function to insert a node at the end of the linked list
void insertNode(ListNode* &head, int val) {
    // Create a new node with the given value
    ListNode* newNode = new ListNode(val);
    
    // If the list is empty, set the new node as the head
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    // Otherwise, traverse to the end of the list
    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Insert the new node at the end of the list
    temp->next = newNode;
}

// Utility function to print the linked list
void printList(ListNode* head) {
    // Traverse the list
    while (head->next != NULL) {
        // Print the value of each node followed by an arrow
        cout << head->val << "->";
        head = head->next;
    }
    // Print the value of the last node
    cout << head->val << endl;
}

int main() {
    // Creation of the first list
    ListNode* head1 = NULL;
    insertNode(head1, 1);
    insertNode(head1, 3);
    insertNode(head1, 1);
    insertNode(head1, 2);
    insertNode(head1, 4);

    // Create an intersection
    ListNode* intersection = head1->next->next->next;

    // Creation of the second list
    ListNode* head2 = NULL;
    insertNode(head2, 3);
    head2->next = intersection;

    // Printing the lists
    cout << "List1: "; 
    printList(head1);
    cout << "List2: "; 
    printList(head2);

    // Checking if an intersection is present
    Solution sol;
    ListNode* answerNode = sol.getIntersectionNode(head1, head2);
    if (answerNode == NULL) {
        cout << "No intersection\n";
    } else {
        cout << "The intersection point is " << answerNode->val << endl;
    }

    return 0;
}