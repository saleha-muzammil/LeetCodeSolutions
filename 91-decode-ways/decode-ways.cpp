#include <vector>
#include <string>
class Solution {
public:
    int numDecodings(string s) {

        if (s=="")
        return 0 ; 

        int n= s.length(); 

        vector<int> num(n + 1);
        for(int i = 1; i <= n; i++){
            num[i] = 0;
        }

        if (s[0]=='0')
        return 0 ; 

        if (s[0] >= '1' && s[0]<='9')
        num[0]= 1; 

        num[1] = num[0];

        int convertor;

        for (int i=2 ; i <=n ;i++)
        {
            if (s[i-1]>='1' && s[i-1] <= '9')
            {
                num[i]= num[i-1];
            }

            string str2= string(1, s[i-2]) + string(1, s[i-1]);
            convertor= stoi(str2);

            if (convertor >= 10 && convertor <= 26)
            {
                    num[i]+= num[i-2]; 
            }

        }

        return num[n];
        
    }
};