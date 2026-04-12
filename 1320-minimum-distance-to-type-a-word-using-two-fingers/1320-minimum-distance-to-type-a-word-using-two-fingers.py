from functools import lru_cache

class Solution:
    def minimumDistance(self, word: str) -> int:
        coords = [(i//6, i%6) for i in range(26)]

        @lru_cache(None)
        def dp(pos1, pos2, idx):
            if idx == len(word):
                return 0
            if pos1 > pos2:
                pos1, pos2 = pos2, pos1
            curr = ord(word[idx]) - 65
            x, y = coords[curr]
            if pos1 == -1:
                cost1 = 0
            else:
                x1, y1 = coords[pos1]
                cost1 = abs(x - x1) + abs(y - y1)
            move1 = cost1 + dp(curr, pos2, idx + 1)
            if pos2 == -1:
                cost2 = 0
            else:
                x2, y2 = coords[pos2]
                cost2 = abs(x - x2) + abs(y - y2)
            move2 = cost2 + dp(pos1, curr, idx + 1)
            return min(move1, move2)

        return dp(-1, -1, 0)