class Solution {
public:

int recursiveFunction(int* array, int k, int index, int n)
{

    if (n==1)
    return array[0]; 

    int loser= (index+k-1) % n ; 
    
    for (int i= loser ; i< n-1 ;i++)
    {
        array[i]= array[i+1]; 
    }

    index= loser % n ;

    return recursiveFunction(array, k, index, n-1); 
}



    int findTheWinner(int n, int k) {

        int* array = new int[n] ; 

        for (int i=0 ; i < n ;i++)
        {
            array[i]= i+ 1 ;
        }

        return recursiveFunction(array, k, 0 , n) ;

        
    }
};