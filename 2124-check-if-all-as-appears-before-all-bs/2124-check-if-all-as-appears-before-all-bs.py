class Solution:
    def checkString(self, s: str) -> bool:
        aAppeared = False
        for i in range(len(s)-1,-1,-1):
            print(i)
            if s[i]=='a':
                aAppeared = True
            else:
                if aAppeared:
                    return False
        return True