class Solution:
    def mostFrequentElement(self, nums):
        maxFreq=0
        maxEle=0

        mpp={}

        for num in nums:
            if num in mpp:
                mpp[num] += 1
            else:
                mpp[num] = 1

        for ele, freq in mpp.items():
            if freq > maxFreq:
                maxFreq = freq
                maxEle = ele
            elif freq == maxFreq:
                maxEle = min(maxEle, ele)

        return maxEle