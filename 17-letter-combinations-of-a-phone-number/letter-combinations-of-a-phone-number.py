L= {'2': "abc" , '3': "def", '4': "ghi" , '5': "jkl" , '6': "mno", '7': "pqrs", '8':"tuv", '9': "wxyz"}


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

        lenDigits, answer = len(digits) , []

        if (digits==""):
             return []
        def bfs (position: int , substring: str): 
            if (position == lenDigits): 
                answer.append(substring)
            else: 
                letters = L[digits[position]]
                for i in letters:
                    bfs(position+1 , substring+i)
        bfs(0, "")
        return answer