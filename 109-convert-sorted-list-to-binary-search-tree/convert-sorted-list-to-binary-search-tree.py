# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def getMid(self,head):
        length= 0 
        current= head 

        while current: 
            length+=1 
            current= current.next 

        current = head 
        count= 0 

        if length == 1:
            temp = current 
            current= None
            return temp 

        while current:
            count+=1 
            if (count == (length//2)):
                temp =current.next
                current.next = None
                return temp
            current= current.next 
        
        return None 
    

    def sortedListToBST(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[TreeNode]
        """
        if not head:
            return None

        mid= self.getMid(head)
        root= TreeNode(mid.val)

        if head== mid:
            return root
        
        root.left = self.sortedListToBST(head)
        root.right= self.sortedListToBST(mid.next)

        return root
        



