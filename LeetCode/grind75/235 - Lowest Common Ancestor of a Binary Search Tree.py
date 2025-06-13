# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution1:
    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        path_p = []
        path_q = []

        self.getPath(root, p, path_p)
        self.getPath(root, q, path_q)
        set_p = set([n.val for n in path_p])
        path_q.reverse()
        for node in path_q:
            if node.val in set_p:
                return node

    def getPath(self, root, target, path):
        if root:
            path.append(root)

            if target.val < root.val:
                self.getPath(root.left, target, path)
            elif target.val > root.val:
                self.getPath(root.right, target, path)
            else:
                return


class Solution2:
    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        while root:
            if p.val > root.val and q.val > root.val:
                root = root.right
            elif p.val < root.val and q.val < root.val:
                root = root.left
            else:
                return root


class Solution3:
    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        q, p = q.val, p.val
        if p > q:
            p, q = q, p  # Make p < q

        stack = [root]
        while stack:
            node = stack.pop()
            if p <= node.val <= q:
                return node
            elif q < node.val:
                stack.append(node.left)
            else:
                stack.append(node.right)
