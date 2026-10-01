#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to recursively heapify the array downwards
    void heapifyDown(vector<int> &arr, int ind) {
        int n = arr.size(); // Size of the array

        // Index of smallest element
        int smallest_Ind = ind; 

        // Indices of the left and right children
        int leftChild_Ind = 2*ind + 1, rightChild_Ind = 2*ind + 2;
        
        // If the left child holds smaller value, update the smallest index
        if(leftChild_Ind < n && arr[leftChild_Ind] < arr[smallest_Ind]) 
            smallest_Ind = leftChild_Ind;

        // If the right child holds smaller value, update the smallest index
        if(rightChild_Ind < n && arr[rightChild_Ind] < arr[smallest_Ind]) 
            smallest_Ind = rightChild_Ind;

        // If the smallest element index is updated
        if(smallest_Ind != ind) {
            // Swap the smallest element with the current index
            swap(arr[smallest_Ind] , arr[ind]);

            // Recursively heapify the lower subtree
            heapifyDown(arr, smallest_Ind);
        }

        return; 
    }

public:
    // Function to convert given array into a min-heap
    void buildMinHeap(vector<int> &nums) {
        int n = nums.size();
        
        // Iterate backwards on the non-leaf nodes
        for(int i = n/2 - 1; i >= 0; i--) {
            // Heapify each node downwards
            heapifyDown(nums, i);
        }
        
        return;
    }
};

// Driver code
int main() {
    vector<int> nums = {6, 5, 2, 7, 1, 7};

    // Input array
    cout << "Input array: ";
    for(int it : nums) cout << it << " ";

    // Creating an object of the Solution class
    Solution sol;

    // Function call to convert the given array into a min-heap
    sol.buildMinHeap(nums);

    // Output array
    cout << "\nMin-heap array: ";
    for(int it : nums) cout << it << " ";

    return 0;
}