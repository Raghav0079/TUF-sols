class Solution {
private:
    // Function to recursively heapify the array downwards
    void heapifyDown(vector<int> &arr, int ind) {
        int n = arr.size(); // Size of the array

        // To store the index of largest element
        int largestInd = ind; 

        // Indices of the left and right children
        int leftChildInd = 2*ind + 1, rightChildInd = 2*ind + 2;
        
        // If the left child holds larger value, update the largest index
        if(leftChildInd < n && arr[leftChildInd] > arr[largestInd]) 
            largestInd = leftChildInd;

        // If the right child holds larger value, update the largest index
        if(rightChildInd < n && arr[rightChildInd] > arr[largestInd]) 
            largestInd = rightChildInd;

        // If the largest element index is updated
        if(largestInd != ind) {
            // Swap the largest element with the current index
            swap(arr[largestInd] , arr[ind]);

            // Recursively heapify the lower subtree
            heapifyDown(arr, largestInd);
        }
        return; 
    }

public:
    // Function to convert a min-heap array to a max-heap array
    vector<int> minToMaxHeap(vector<int> nums) {
        int n = nums.size();
            
        // Iterate backwards on the non-leaf nodes
        for(int i = n/2 - 1; i >= 0; i--) {
            // Heapify each node downwards
            heapifyDown(nums, i);
        }
        
        return nums;
    }
};
