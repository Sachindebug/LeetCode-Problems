class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        mx = max(nums)
        count, res = 0, 0 
        for num in nums:
            if num==mx:
                count+=1
            else:
                res = max(res,count)
                count = 0
        res = max(res,count)
        return res