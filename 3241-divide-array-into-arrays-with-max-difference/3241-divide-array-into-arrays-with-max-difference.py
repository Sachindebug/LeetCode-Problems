class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        result  = []
        nums.sort()
        n , idx = 3, 0
        while idx<len(nums):
            if nums[idx+n-1]-nums[idx] > k:
                result = []
                break
            else:
                result.append(nums[idx:idx+n])
            idx+=n
        return result
        