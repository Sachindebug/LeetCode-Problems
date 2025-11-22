class Solution:
    def pivotInteger(self, n: int) -> int:
        if n<=1:
            return 1

        sum_till_n = (n*(n+1))//2
        curr_sum = 0
        for i in range(1,n):
            curr_sum += i
            if curr_sum == sum_till_n - curr_sum + i:
                return i
        return -1
