class Solution{	
	public:
		int arraySum(vector<int>& nums){
			return sum(nums,0);
		}
private:
        int sum(vector<int> & nums , int left){
            if (left >= nums.size()) {
            return 0;
        }
        return nums[left] + sum(nums,left+1);
        }
};