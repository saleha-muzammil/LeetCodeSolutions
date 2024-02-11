"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution(object):
    def flatten(self, head):
        """
        :type head: Node
        :rtype: Node
        """

        current= head 

        while current: 

            if current.child: 
                temp = current.next 
                current.next = current.child 
                current.child.prev= current
                current.child= None 

                childlist = current.next 

                while childlist.next: 
                    childlist = childlist.next 
                
                childlist.next= temp 

                if temp:
                    temp.prev= childlist 

            current= current.next 
                    
        return head