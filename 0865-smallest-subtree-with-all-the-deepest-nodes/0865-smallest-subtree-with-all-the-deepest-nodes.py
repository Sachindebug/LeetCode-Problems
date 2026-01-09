# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        max_depth = {}
        res = self.recordDepth(root,max_depth)
        print(res)
        return self.findNode(root,max_depth)

    def recordDepth(self, root: Optional[TreeNode], max_depth):
        if root==None:
            return 0
        left_depth = self.recordDepth(root.left,max_depth)
        right_depth = self.recordDepth(root.right,max_depth)
        res = 1+max(left_depth,right_depth)
        max_depth[root] = [left_depth,right_depth]
        return res

    def findNode(self, root: Optional[TreeNode], max_depth):
        if root==None:
            return root
        val = max_depth[root]
        if val[0]==val[1]:
            return root
        elif val[0]> val[1]:
            return self.findNode(root.left,max_depth)
        return self.findNode(root.right,max_depth)
