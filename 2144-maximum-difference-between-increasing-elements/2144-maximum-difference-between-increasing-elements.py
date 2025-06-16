class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        idx = len(nums)-1
        mx,res = 0,-1
        while idx>=0:
            if nums[idx]< mx:
                res = max(res,mx-nums[idx])
            mx = max(mx,nums[idx])
            idx-=1
        return res
