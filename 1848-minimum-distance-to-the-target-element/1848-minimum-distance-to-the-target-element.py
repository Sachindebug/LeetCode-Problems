class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        res = len(nums)
        for i in range(0,len(nums)):
            if nums[i]==target:
                res = min(res,abs(i-start))
        return res