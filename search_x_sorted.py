class Solution:

    def func(self, nums, low, high, target):
        # base case
        if low > high:
            return -1

        mid = low + (high - low)//2
        
        if nums[mid] == target:
            ind = mid
 
        elif nums[mid] > target:
            ind = self.func(nums, low, mid-1, target)
        else:
            ind = self.func(nums, mid+1, high, target)

        return ind  


    def search(self, nums, target):
        n = len(nums)

        return self.func(nums, 0, n-1, target)
