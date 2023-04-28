class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:

        freq= {}
        for i in deck:
            freq[i]= freq.get(i,0)+ 1
            
        listfreq= list(freq.values())

        ans= reduce(gcd, listfreq)

        if ans > 1:
            return True

        return False 




            

                














