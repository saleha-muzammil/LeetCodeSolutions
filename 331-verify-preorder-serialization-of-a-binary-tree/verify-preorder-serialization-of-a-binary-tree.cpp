#include <stack>
#include <string>

class Solution {
public:
    bool isValidSerialization(std::string preorder) {
        std::stack<char> S;

        for (int i = 0; i < preorder.length(); i++) {
            if (preorder[i] == ',') continue;

            if (preorder[i] == '#') {

                while (!S.empty() && S.top() == '#') {
                    S.pop(); 
                    if (S.empty()) return false; 
                    S.pop(); 
                }
                S.push('#'); 
            } else {
                while (i < preorder.length() && preorder[i] != ',') i++;
                S.push('1'); 
            }
        }
        return S.size() == 1 && S.top() == '#';
    }
};
