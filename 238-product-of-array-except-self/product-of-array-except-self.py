class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        array =[]
        num = 1 
        zeroflag= False

        for i in nums: 
            if i ==0 and not zeroflag:
                zeroflag= True
            elif i==0 and zeroflag:
                num=0
            else:
                num= num*i 
        
        for j in nums:
            if j != 0 and not zeroflag:
                array.append(num/j)
            elif j!=0 and zeroflag:
                array.append(0)
            else: 
                array.append(num)
        
        return array
            
        