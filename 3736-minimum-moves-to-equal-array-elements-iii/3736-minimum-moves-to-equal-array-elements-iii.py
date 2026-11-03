class Solution:
    def minMoves(self, nums: List[int]) -> int:
        return sum(abs(num-max(nums)) for num in nums)