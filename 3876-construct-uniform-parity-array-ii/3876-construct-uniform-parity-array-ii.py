class Solution:
    def uniformArray(self, nums1):
        mini = float('inf')
        odd = False

        for t in nums1:
            if t % 2 == 1:
                odd = True
                mini = min(mini, t)

        if not odd:
            return True

        for t in nums1:
            if t % 2 == 0 and mini > t:
                return False

        return True