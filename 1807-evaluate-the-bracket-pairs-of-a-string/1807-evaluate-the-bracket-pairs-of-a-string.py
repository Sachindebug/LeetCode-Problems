class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        dct = {}
        for ele in knowledge:
            dct[ele[0]] = ele[1]
        total_string = ""
        curr = ""
        for c in s:
            if c=='(':
                total_string+=curr
                curr=""
            elif c==')':
                total_string+=dct.get(curr,'?')
                curr=""
            else:
                curr+=c
        total_string+=curr
        return total_string
