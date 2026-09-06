from functools import lru_cache

class Solution:
    def numDistinct(self, s: str, t: str) -> int:

        if len(s) < len(t):
            return 0

        @lru_cache(None)
        def recurse(i: int, j: int) -> int:

            if j == len(t):
                return 1

            if i == len(s):
                return 0

            if s[i] == t[j]:
                take = recurse(i + 1, j + 1)
                leave = recurse(i + 1, j)
                return take + leave

            return recurse(i + 1, j)

        return recurse(0, 0)