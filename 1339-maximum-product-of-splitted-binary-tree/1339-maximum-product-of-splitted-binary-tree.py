# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    MOD = 10**9 + 7

    def getTotalSum(self, root, subtree_sum):
        if not root:
            return 0

        left_sum = self.getTotalSum(root.left, subtree_sum)
        right_sum = self.getTotalSum(root.right, subtree_sum)

        total = root.val + left_sum + right_sum
        subtree_sum[root] = total
        return total

    def getMaxProduct(self, root, total_sum, subtree_sum):
        if not root:
            return 0

        current = subtree_sum[root]
        remaining = total_sum - current
        product = current * remaining 

        return max(
            product,
            self.getMaxProduct(root.left, total_sum, subtree_sum),
            self.getMaxProduct(root.right, total_sum, subtree_sum)
        )

    def maxProduct(self, root) -> int:
        subtree_sum = {}
        total_sum = self.getTotalSum(root, subtree_sum)
        max_product = self.getMaxProduct(root, total_sum, subtree_sum)
        return max_product % self.MOD
