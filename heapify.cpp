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

    // Function to recursively heapify the array upwards
    void heapifyUp(vector<int> &arr, int ind) {
        int parent_Ind = (ind - 1)/2; 

        // If current index holds smaller value than the parent
        if(ind > 0 && arr[ind] < arr[parent_Ind]) {
            // Swap the values at the two indices
            swap(arr[ind], arr[parent_Ind]);

            // Recursively heapify the upper nodes
            heapifyUp(arr, parent_Ind);
        } 

        return;
    }

public:
    // Function to implement the heapify algorithm for a min-heap
    void heapify(vector<int> &nums, int ind, int val) {

        // If the current value is replaced with a smaller value
        if(nums[ind] > val) {
            nums[ind] = val;
            heapifyUp(nums, ind);
        }

        // Else if the current value is replaced with a larger value
        else {
            nums[ind] = val;
            heapifyDown(nums, ind);
        }

        return;
    }
};

// Driver code
int main() {
    vector<int> nums = {1, 4, 5, 5, 7, 6};
    int ind = 5, val = 2;

    // Input array
    cout << "Input array: ";
    for(int it : nums) cout << it << " ";

    // Creating an object of the Solution class
    Solution sol;

    // Function call to heapify the array
    sol.heapify(nums, ind, val);

    // Output array
    cout << "\nModified array after heapifying: ";
    for(int it : nums) cout << it << " ";

    return 0;
}