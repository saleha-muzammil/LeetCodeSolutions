# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def zigzag(self, stack, count, mainArray):

        stack2=[]
        array= []

        while stack:
            node= stack.pop()

            if node:
                array.append(node.val)

                if count ==1 :
                    if node.left:
                        stack2.append(node.left)
                    if node.right:
                        stack2.append(node.right)
                
                else:
                    if node.right:
                        stack2.append(node.right)
                    if node.left:
                        stack2.append(node.left)                
        if array:
            mainArray.append(array) 

        if stack2:  
            self.zigzag(stack2, 1- count, mainArray)
    
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        mainArray=[]
        array=[]
        if root is None:
            return mainArray

        array.append(root.val)
        mainArray.append(array)

        if root.left or root.right is not None:
            stack=[]
            stack.append(root.left)
            stack.append(root.right)
            self.zigzag(stack, 0, mainArray)
        print(mainArray)
        return mainArray


        
