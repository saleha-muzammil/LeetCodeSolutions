// C++ solution to Dtring to Integar (atoi) in C++ 
// URL: https://leetcode.com/problems/string-to-integer-atoi

//Approach
//Straightforward Iterative

//Complexity
//- Time complexity:
//O(n)
  
//-Space complexity:
//O(n)
//Code

class Solution {
public:
    int myAtoi(string s) {

        char sign = '+' ; 
        int number= 0 ; 
        int temp=0 ;
        char ch='\0';
        int* array = new int[s.length()];
        int j=0 ;
        bool flag = false ; 
        int isatstart= 0; 


        for (int i=0;i < s.length(); i++)
        {
            ch = s[i] ;

            if(ch==' ')
            {
            if (j> 0 || i!= isatstart)
            break; 
            isatstart++; 
            continue ;
            }

            else if (flag==false && (ch=='+' || ch=='-') && i==isatstart)
            {
            sign = ch ;
            flag = true;
            } 

            else if (ch>= '0' && ch<= '9')
            {
            array[j]= ch- '0' ; 
            j++;
            }
            else 
            break ; 
        }


        for (int i=0; i< j ;i++)
        {
            temp = array[i] ; 
            
            if (number <= (INT_MAX - temp) /10)
            number=number*10 + temp ;


            else if (sign=='+') 
            {
            array = nullptr;
            delete[] array ;
            return INT_MAX ; 
            }
            else 
            {
                array = nullptr;
                delete[] array ;
                return INT_MIN ;
            }
        }

        if (sign=='-')
             number*=-1 ;

        array = nullptr;
        delete[] array ;
        return number; 
    }
};
