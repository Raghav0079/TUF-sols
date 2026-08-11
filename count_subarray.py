class Solution:
    def subarraySumDivisbleByK(self, nums, k):
        remainder_counts = {0:1}

        curr_sum =0 
        total_subarray = 0

        for num in nums:
            curr_sum += num
            remainder = curr_sum % k 
            if remainder in remainder_counts:
                total_subarray += remainder_counts[remainder]
                remainder_counts[remainder] += 1

            else:
                remainder_counts[remainder] = 1

        return total_subarray
      
