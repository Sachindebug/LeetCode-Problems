import math
class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n==0:
            return 1
        p = int(math.log2(n))
        q = 1<<(p+1)
        return n^(q-1)

