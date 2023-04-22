// Solution to Longest Substring Without Repeating Characters

class Solution {
public:


    int lengthOfLongestSubstring(string s) {

        int size= s.length() ;

        if (size==0)
        return 0 ; 
        bool flag = false ;
        int settag =-1 ; 

        int* array = new int[size] ; 
        array[0]=1 ; 

        for (int i=1 ;i < size ;i++)
        {
            flag = false ; 
            array[i]= array[i-1]; 
            for (int j=i-1 ; j > settag; j--)
            {
                if (s[i]== s[j])
                {
                    flag = true ;

                    int k= j ;
                    array[i]=1 ;
                    for (; k > settag ;k--)
                    {
                        if (s[k]== s[i])
                        {
                         break ;   
                        }
                    }

                    array[i]= i-k;

                    settag = j ;
                }
            }
            if (!flag)
            array[i]++;

        }
        

        int max =-1; 
        for (int i=0 ;i < size ;i++)
        {
            if (array[i]> max)
            {
            max = array[i]; 
            }
        }
        return max; 
        
    }
};
