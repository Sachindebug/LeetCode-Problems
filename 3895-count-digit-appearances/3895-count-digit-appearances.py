class Solution:
    def countDigitOccurrences(self, nums: list[int], digit: int) -> int:
        return sum([str(ele).count(str(digit)) for ele in nums])