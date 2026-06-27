class Solution:
    def moveZeroes(self, nums):
        insert_pos = 0 

        for i in range(len(nums)):
            if nums[i] != 0:
                nums[i], nums[insert_pos] = nums[insert_pos], nums[i] 
                insert_pos += 1

if __name__ == "__main__":
    arr = [1, 0, 2, 3, 2, 0, 0, 4, 5, 1]

    sol = Solution()
    sol.moveZeroes(arr)

    print(" ".join(map(str, arr)))