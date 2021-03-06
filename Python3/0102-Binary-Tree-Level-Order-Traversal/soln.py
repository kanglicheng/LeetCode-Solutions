# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        nodes = [root]
        res = []
        while nodes:
            temp = []
            vals = []
            for node in nodes:
                vals.append(node.val)
                if node.left:
                    temp.append(node.left)
                if node.right:
                    temp.append(node.right)
            nodes = temp
            res.append(vals)
        return res