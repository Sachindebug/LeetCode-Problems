class Solution:
    def findLHS(self, nums: List[int]) -> int:
        nums.sort()
        mp = defaultdict(int)
        for num in nums:
            mp[num]+=1
        res = 0
        idx = 0
        while idx < len(nums)-1:
            if(nums[idx]==nums[idx+1]-1):
                res = max(res,mp[nums[idx]]+mp[nums[idx+1]])
            idx+=1
        return res
