class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        nums.reverse()
        n = len(nums)
        res = [True]*n
        curr_val = 0
        i = n-1
        while i >=0:
            curr_val = curr_val*2+nums[i]
            res[i] = (curr_val%5==0)
            i-=1
        res.reverse()
        return res