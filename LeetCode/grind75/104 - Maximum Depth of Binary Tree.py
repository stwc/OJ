# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution1:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        result = 0

        def dfs(root, depth):
            if not root:
                return

            depth += 1
            nonlocal result
            if depth > result:
                result = depth

            dfs(root.left, depth)
            dfs(root.right, depth)

        dfs(root, 0)
        return result


class Solution2:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))


class Solution3:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        q = deque()
        q.append(root)
        depth = 0

        while q:
            depth += 1

            for _ in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

        return depth
