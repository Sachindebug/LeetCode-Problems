class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        diff = arr[1]-arr[0]
        idx = 1
        while idx<len(arr)-1:
            curr_diff = arr[idx+1]-arr[idx]
            if curr_diff!=diff:
                return False
            idx+=1
        return True