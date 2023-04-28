class Solution {
public:
    int addDigits(int num) 
    {

        if (num/10== 0)
        return num ;

        int sum= 0 ;
        int n= num ;
        while (n/10!=0)
        {
            sum+= (n%10) ; 
            n/=10 ;

        }
        return addDigits(n+ sum);
        
    }
};
