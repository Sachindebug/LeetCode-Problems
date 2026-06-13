class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        res = ""
        for word in words:
            weight = 0
            for c in word:
                pos = ord(c)-97
                weight+=weights[pos]
            new_c = chr(25-(weight%26)+ 97)
            res+=new_c
        return res
