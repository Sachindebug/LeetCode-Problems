class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        nums.sort()
        l1 = nums[-1] * nums[-2]
        l2 = nums[-1] * nums[0]
        l3 = nums[0] * nums[1]
        max_nums = 100000
        return max(l1*max_nums,l2*-1*max_nums, l3*max_nums)