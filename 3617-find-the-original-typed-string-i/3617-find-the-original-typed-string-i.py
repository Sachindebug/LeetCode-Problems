class Solution:
    def possibleStringCount(self, word: str) -> int:
        idx,size = 1, len(word)
        ans,count,res = 1,0,0
        while idx<size:
            if word[idx-1] == word[idx]:
                ans+=1
            else:
                if ans > 1:
                    res+=ans
                    count+=1
                ans = 1
            idx+=1
        if ans > 1:
            res+=ans
            count+=1
        return res-count+1
