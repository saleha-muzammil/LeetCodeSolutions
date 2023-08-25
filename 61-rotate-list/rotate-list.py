# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        size = self.sizeCalc(head)
                
        if size==0: 
            return head 
        k = k % size 

        if k==0 : 
            return head 
        else: 
            temp1 = head 
            while (temp1.next.next is not None):
                temp1 = temp1.next
            temp2 = temp1.next 
            temp1.next = None
            temp2.next = head 
            return self.rotateRight(temp2 , k-1)

    def sizeCalc(self, head: Optional[ListNode]): 
        size= 0 
        if head== None or head.next == None: 
            return size 
        while (head is not None):
            size+=1 
            head= head.next 
        return size 
    
        


    
    

            