class Solution {
public:
    int climbStairs(int n) {

        int* array = new int[n] ; 

        for (int i=0 ; i <n ;i++)
        array[i]= 0 ;

        array[0]= 1 ;
        if (n>1)
        array[1]= 2 ; 

        for (int i=2 ;i < n ;i++)
        {
            array[i]= array[i-1] + array[i-2];
        }

        int result = array[n-1];
        delete[] array ; 
        return result;
    }
};