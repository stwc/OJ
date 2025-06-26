# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        res = [0]
        self.dfs(root, res)
        return res[0]

    def dfs(self, root, res):
        if not root:
            return 0

        left = self.dfs(root.left, res)
        right = self.dfs(root.right, res)

        sum_depth = left + right
        if sum_depth > res[0]:
            res[0] = sum_depth

        if left > right:
            max_depth = left
        else:
            max_depth = right

        return max_depth + 1
