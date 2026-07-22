class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        if(nums.size() < 2){
            return -1;
        }

        int large = INT_MIN;
        int second_large = INT_MIN;

        for(int i=0 ; i < nums.size() ; i++){
            if(nums[i] > large){
                second_large = large ;
                large = nums[i];
            }
            else if (nums[i] > second_large && nums[i] != large){
                second_large = nums[i];
            }
        }

        return second_large == INT_MIN ? -1 : second_large;

      
    }
};