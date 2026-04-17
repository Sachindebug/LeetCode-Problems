class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        def getReverse(n: int) -> int:
            res = 0
            while n>0:
                res = res*10+(n%10)
                n//=10
            return res

        pos = {}
        ans = len(nums)+1
        for idx,num in enumerate(nums):
            rev = getReverse(num)
            if num in pos.keys():
                ans = min(ans,idx-pos[num])
            pos[rev] = idx
        if ans > len(nums): return -1
        return ans