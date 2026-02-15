class Solution:
    def addBinary(self, a: str, b: str) -> str:
        ans, carry = [], 0
        for a_bit, b_bit in zip_longest(reversed(a), reversed(b), fillvalue = '0'):
            carry, s = divmod(int(a_bit) + int(b_bit) + carry, 2)
            ans.append(str(s))
        if carry: ans.append('1')
        return ''.join(reversed(ans))