class Solution:
    def minCost(self, nums):
        n = len(nums)
        best = float('inf')
        streak = 1
        for i in range(1, n + 1):
            if i < n and nums[i] == nums[i - 1]:
                streak += 1
                continue
            # Run is [start, end]
            start = i - streak
            end = i - 1
            streak = 1
            # Endpoints can't be sources
            if end == 0 or start == n - 1:
                continue
            best = min(best, nums[end] * (n - (end - start + 1)))
        return best