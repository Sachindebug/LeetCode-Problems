class Solution:
    def minOperations(self, s: str) -> int:
        N = len(s)
        if s == ''.join(list(sorted(s))):
            return 0  
        if N == 2:
            return -1
            
        s1 = ''.join([s[0]] + list(sorted(s[1:])))
        s2 = ''.join(list(sorted(s[:N - 1])) + [s[-1]])
        s3 = ''.join(list(sorted(s1[:N - 1])) + [s1[-1]])
        s4 = ''.join([s2[0]] + list(sorted(s2[1:])))
        s5 = ''.join([s3[0]] + list(sorted(s3[1:])))
        s6 = ''.join(list(sorted(s4[:N - 1])) + [s4[-1]])
        s = ''.join(list(sorted(s)))

        if s1 == s or s2 == s:
            return 1

        if s3 == s or s4 == s:
            return 2

        if s5 == s or s6 == s:
            return 3

        return -1