class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        divisors = []

        for k in range(1, n + 1):
            if n % k == 0:
                divisors.append(k)

        ans = 0

        for k in divisors:
            valid = True
            prevMax = -1

            for i in range(0, n, k):
                sub = nums[i:i + k]
                mn, mx = min(sub), max(sub)

                if mn < prevMax:
                    valid = False
                    break

                count = 0

                for j in range(i + 1, i + k):
                    if nums[j] < nums[j - 1]:
                        count += 1

                if nums[i + k - 1] > nums[i]:
                    count += 1

                if count > 1:
                    valid = False
                    break

                prevMax = mx

            if valid:
                ans += k

        return ans