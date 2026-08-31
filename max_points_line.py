import math
from collections import defaultdict

class Solution:
    def maximumPointsOnALine(self, nums: list[list[int]]) -> int:
        n = len(nums)
        if n <= 2:
            return n
            
        max_points = 1
        
        for i in range(n):
            slopes = defaultdict(int)
            duplicate = 0
            current_max = 0
            
            for j in range(i + 1, n):
                dx = nums[j][0] - nums[i][0]
                dy = nums[j][1] - nums[i][1]

                gcd = math.gcd(dx, dy)
                dx //= gcd
                dy //= gcd
                
                if dx < 0 or (dx == 0 and dy < 0):
                    dx = -dx
                    dy = -dy
                    
                slope_key = (dy, dx)
                slopes[slope_key] += 1
                current_max = max(current_max, slopes[slope_key])
                
            max_points = max(max_points, current_max + 1)
            
        return max_points
