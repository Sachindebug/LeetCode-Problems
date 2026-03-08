class Solution:
    def minimumIndex(self, capacity: list[int], itemSize: int) -> int:
        minIndex,minValue = -1,10001
        for i,c in enumerate(capacity):
            if c>=itemSize and c<minValue:
                minValue = c
                minIndex = i 
        return minIndex