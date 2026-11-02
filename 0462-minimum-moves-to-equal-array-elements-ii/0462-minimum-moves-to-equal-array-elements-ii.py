class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()
        n = len(nums)
        median = -1
        mid_index = n//2
        if n%2==0:
            median = (nums[mid_index]+nums[mid_index-1])//2
        else:
            median = nums[mid_index]
        res = 0
        for num in nums:
            res+=abs(median-num)
        return res