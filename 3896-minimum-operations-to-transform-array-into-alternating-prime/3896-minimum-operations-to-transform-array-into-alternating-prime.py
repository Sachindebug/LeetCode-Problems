import bisect
class Solution:
    def minOperations(self, nums: list[int]) -> int:
        qerlanovid = nums[:]
        max_val = max(nums) + 100

        is_prime = [True] * (max_val + 1)
        is_prime[0] = is_prime[1] = False

        for i in range(2, int(max_val ** 0.5) + 1):
            if is_prime[i]:
                for j in range(i * i, max_val + 1, i):
                    is_prime[j] = False

        primes = [i for i in range(2, max_val + 1) if is_prime[i]]

        ops = 0
        for i, num in enumerate(qerlanovid):
            if i % 2 == 0:
                idx = bisect.bisect_left(primes, num)
                target = primes[idx]
            else:
                curr = num
                while curr <= max_val and is_prime[curr]:
                    curr += 1
                target = curr
            ops += target - num

        return ops