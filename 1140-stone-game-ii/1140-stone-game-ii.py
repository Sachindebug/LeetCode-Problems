from typing import List
from functools import lru_cache

class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        suffix = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suffix[i] = suffix[i + 1] + piles[i]

        @lru_cache(None)
        def recurse(idx: int, m: int):
            if idx >= n:
                return 0
            res = 0
            for x in range(1, 2 * m + 1):
                if idx + x > n:
                    break
                opponent = recurse(idx + x, max(m, x))
                current = suffix[idx] - opponent
                res = max(res, current)
            return res

        return recurse(0, 1)