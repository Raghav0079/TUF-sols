class Solution:
    def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
        max_streak = 0
        curr_streak = 0
        
        for num in nums:
            if num == 1:
                curr_streak += 1
                max_streak = max(max_streak, curr_streak)
            else:
                curr_streak = 0
                
        return max_streak
