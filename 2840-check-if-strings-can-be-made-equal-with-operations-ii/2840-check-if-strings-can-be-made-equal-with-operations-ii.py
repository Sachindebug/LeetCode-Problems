class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        odd_pos,even_pos={},{}
        for i in range(0,26):
            odd_pos[chr(ord('a')+i)]=0
            even_pos[chr(ord('a')+i)]=0
        
        for i in range(0,len(s1)):
            if i%2:
                odd_pos[s1[i]]+=1
                odd_pos[s2[i]]-=1
            else:
                even_pos[s1[i]]+=1
                even_pos[s2[i]]-=1
        
        for k in odd_pos.keys():
            if odd_pos[k]!=0 or even_pos[k]!=0:
                return False
        return True