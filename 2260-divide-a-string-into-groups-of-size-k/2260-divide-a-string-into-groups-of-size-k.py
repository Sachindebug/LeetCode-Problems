class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        n = len(s)
        if(n%k!=0):
            rem = k - (n%k)
            for i in range(0,rem):
                s+=(fill)

        res = []
        idx = 0
        while idx<len(s):
            res.append(s[idx:idx+k])
            idx+=k
        return res