class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n1, n2 = len(nums1), len(nums2)
        memo = {}
        def dfs(i, j):
            if (i, j) in memo:
                return memo[(i, j)]
            if i >= n1 or j >= n2:
                return -inf
            
            prod = nums1[i] * nums2[j]
            memo[(i, j)] = max(prod, prod + dfs(i+1,j+1), dfs(i+1,j), dfs(i,j+1))
            return memo[(i, j)]
        return dfs(0, 0)