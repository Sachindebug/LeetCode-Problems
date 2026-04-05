class Solution:
    def countSteps(self, nums, idx) -> int:
        count = 0
        for i in range(idx,len(nums)-1,2):
            left,right = nums[i-1],nums[i+1]
            mx = max(left,right)
            count += max(0,mx-nums[i]+1)
        return count

    def minIncrease(self, nums: List[int]) -> int:
        n = len(nums)
        if n%2: return self.countSteps(nums,1)

        @lru_cache(None)    
        def countDp(currIdx, skipped)-> int:
            if currIdx >= len(nums)-1:
                return 0
            left,right = nums[currIdx-1],nums[currIdx+1]
            mx = max(left,right)
            count = max(0,mx-nums[currIdx]+1)
            not_skip = count+countDp(currIdx+2,skipped)
            skip = countDp(currIdx+1,1-skipped)
            if skipped:
                return not_skip
            return min(skip,not_skip)

        return countDp(1,0)