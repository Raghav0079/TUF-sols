class Solution{	
	public:
		vector<int> reverseArray(vector<int>& nums){
            reverse(nums, 0, nums.size() - 1);
            return nums;

        }

    private:
        void reverse(vector<int> & nums , int left , int right){
            if(left >= right){
                return;
            }
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            reverse(nums,left+1,right-1);
        }
        
};