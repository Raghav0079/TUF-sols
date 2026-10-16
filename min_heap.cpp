class Solution {
private:
    vector<int> arr; // list to store the min-heap
    int count; // to store the count of elements in min-heap
    

    void heapifyUp(vector<int> &arr, int ind) {
        int parentInd = (ind - 1)/2; 
        if(ind > 0 && arr[ind] < arr[parentInd]) {
            swap(arr[ind], arr[parentInd]);
            heapifyUp(arr, parentInd);
        } 

        return;
    }
    
    void heapifyDown(vector<int> &arr, int ind) {
        int n = arr.size(); // Size of the array
        int smallestInd = ind; 
        int leftChildInd = 2*ind + 1, rightChildInd = 2*ind + 2;
        
        if(leftChildInd < n && arr[leftChildInd] < arr[smallestInd]) 
            smallestInd = leftChildInd;

        if(rightChildInd < n && arr[rightChildInd] < arr[smallestInd]) 
            smallestInd = rightChildInd;

        if(smallestInd != ind) {
            swap(arr[smallestInd] , arr[ind]);
            heapifyDown(arr, smallestInd);
        }

        return; 
    }
    
public:
    void initializeHeap(){
        arr.clear();
        count = 0;
    }
    
    void insert(int key){
        arr.push_back(key);
        heapifyUp(arr, count);
        count = count+1; // Increment the counter;
        
        return;
    }
        
    void changeKey(int index, int new_val){

        if(arr[index] > new_val) {
            arr[index] = new_val;
            heapifyUp(arr, index);
        }

        else {
            arr[index] = new_val;
            heapifyDown(arr, index);
        }

        return;
    }
    
    void extractMin(){
        int ele = arr[0]; // minimum value in the heap
        
        swap(arr[0], arr[count-1]); 
        
        arr.pop_back(); // Pop the minimum value from the list
        count = count - 1; // Decrement the counter
        heapifyDown(arr, 0);
    }
    
    bool isEmpty(){
        return (count == 0);
    }
    
    int getMin(){
        return arr[0];
    }
    
    int heapSize(){
        return count;
    }
};