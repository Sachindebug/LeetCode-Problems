class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        char_count = defaultdict(int)
        for c in text:
            char_count[c]+=1
        ans = len(text)
        for c in "balon":
            if c not in 'lo': ans = min(ans,char_count[c])
            else: ans = min(ans,char_count[c]//2)
        return ans

