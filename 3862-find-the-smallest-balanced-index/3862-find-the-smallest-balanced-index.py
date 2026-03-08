class Solution:
    def smallestBalancedIndex(self, nums: list[int]) -> int:
        total_sum = sum(nums)
        curr_sum,curr_prod, ans = 0,1,-1
        for i in range(len(nums)-1,0,-1):
            left_sum = total_sum-(curr_sum+nums[i])
            if(left_sum==curr_prod):
                ans = i
            elif(curr_prod>left_sum):
                break
            curr_sum+=nums[i]
            curr_prod*=nums[i]
        return ans



