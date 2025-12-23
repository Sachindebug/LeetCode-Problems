from typing import List
from functools import lru_cache

class Solution:
    def nextIndex(self, events: List[List[int]], idx: int, target: int) -> int:
        left, right = idx + 1, len(events) - 1
        ans = -1
        
        while left <= right:
            mid = (left + right) // 2
            if events[mid][0] >= target:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        
        return ans

    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort()
        
        @lru_cache(None)
        def recurse(idx: int, count: int) -> int:
            if idx >= len(events) or count == 2:
                return 0
            
            not_pick = recurse(idx + 1, count)
            
            next_idx = self.nextIndex(events, idx, events[idx][1] + 1)
            pick = events[idx][2]
            if next_idx != -1:
                pick += recurse(next_idx, count + 1)
            
            return max(pick, not_pick)
        
        return recurse(0, 0)
