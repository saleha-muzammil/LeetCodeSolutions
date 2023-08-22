# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def inorder (self, root, array):
        if not root:
            return 
        
        else: 
            self.inorder(root.left, array)
            array.append(root.val)
            self.inorder(root.right, array)
            



    def getAllElements(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: List[int]
        """
        list1= []
        list2=[]
        self.inorder(root1, list1)
        self.inorder(root2, list2)
        l = list1 + list2 
        l.sort()

        return l 
        
