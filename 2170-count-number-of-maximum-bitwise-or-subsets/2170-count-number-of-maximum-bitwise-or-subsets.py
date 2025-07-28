class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        maxor = 0
        for num in nums:
            maxor |= num
        return self.recurse(nums,0,0,maxor)
    
    def recurse(self, nums: List[int], idx: int, curr: int, total: int) -> int:
        if idx==len(nums):
            return total==curr
        return self.recurse(nums,idx+1,curr,total)+self.recurse(nums,idx+1,curr|nums[idx],total)
        