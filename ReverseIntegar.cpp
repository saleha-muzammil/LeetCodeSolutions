// cpp solution to https://leetcode.com/problems/reverse-integer

// space complexity : O(1) , time complexity: O(log(x))


class Solution {
public:
    int reverse(int x) {


        bool isneg= false  ; 
        if (x <0)
        {
            if (x < INT_MAX*-1)
            return 0 ;
            x*= -1 ;
        isneg= true  ;
        }

        int n = x  ; 
        int reverse= 0 ; 

        for (int i=0 ; n >0 ; i++)
        {
            if (reverse > INT_MAX/10)
            return 0 ; 

            reverse*= 10; 
            reverse =reverse +  n%10 ;
            n= n/10 ; 

        }

        if (isneg)
        reverse*= -1 ;

        return reverse ; 
        
    }
};
