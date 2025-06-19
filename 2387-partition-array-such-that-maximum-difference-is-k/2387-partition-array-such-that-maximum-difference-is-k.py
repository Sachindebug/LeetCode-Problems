class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        count,idx,n,prev = 1,0,len(nums),0
        while idx<n:
            if nums[idx]-nums[prev] <= k:
                idx+=1
            else:
                count+=1
                prev = idx
                idx+=1
        return count