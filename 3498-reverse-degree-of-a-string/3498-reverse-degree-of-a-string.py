class Solution:
    def reverseDegree(self, s: str) -> int:
        sum = 0 
        for i in range(0,len(s)):
            sum+=((i+1)*(ord('z')-ord(s[i])+1))
        return sum