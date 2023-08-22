class Solution(object):
    def myPow(self, x, n):
        num = 1.0000
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if (n < 0): 
            n= -n
            if n % 2 ==0 : 
                half_pow = self.myPow(x, n //2)
                num= half_pow * half_pow
            else:
                half_pow= self.myPow(x, (n-1)//2)
                num= x * half_pow * half_pow
            float(num)
            num= 1 / num
        elif (n > 0):
            if n % 2 ==0 : 
                half_pow = self.myPow(x, n //2)
                num= half_pow * half_pow
            else:
                half_pow= self.myPow(x, (n-1)//2)
                num= x * half_pow * half_pow 
        return num 
