class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        if s1==s2:
            return True
        elif sorted(s1)!=sorted(s2):
            return False
        return (s1[0]==s2[2] and s1[2]==s2[0]) or (s1[1]==s2[3] and s1[3]==s2[1])