class Solution:
    @staticmethod
    def isPrime(n: int):
        if n <= 1:
            return False
        if n==2:
            return True
        i = 2
        while i*i<=n:
            if n%i==0:
                return False
            i+=1
        return True

    def splitArray(self, nums: List[int]) -> int:
        total = 0
        for i, num in enumerate(nums):
            if self.isPrime(i):
                total += num
            else:
                total -= num
        return abs(total)