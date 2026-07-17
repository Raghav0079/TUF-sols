class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;
        priority_queue<int> leftPQ, rightPQ;
        vector<bool> leftGood(n, false);
        

        for (int i = 0; i < k; i++) {
            leftPQ.push(nums[i]);
            rightPQ.push(nums[n - 1 - i]);
        }
        

        for (int i = k; i < n - k; i++) {
            if (nums[i] > leftPQ.top()) {
                leftGood[i] = true;
            } else {
                leftPQ.pop();
                leftPQ.push(nums[i]);
            }
        }

        for (int i = n - k - 1; i >= k; i--) {
            if (nums[i] > rightPQ.top() && leftGood[i]) {
                result++;
            } else {
                rightPQ.pop();
                rightPQ.push(nums[i]);
            }
        }
        return result;
    }
};