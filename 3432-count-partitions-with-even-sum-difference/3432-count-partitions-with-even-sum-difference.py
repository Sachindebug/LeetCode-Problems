class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        total = sum(nums)
        curr_sum = 0
        count = 0
        for num in nums:
            curr_sum+=num
            count+=((total-(2*curr_sum))%2==0)
        return count-(total%2==0)