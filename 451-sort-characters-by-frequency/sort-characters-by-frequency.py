class Solution(object):
    def frequencySort(self, s):

        hashmap= {}

        for i in range(0, len(s)):

            if s[i] in hashmap: 
                hashmap[s[i]]+=1 
            
            else: 
                hashmap[s[i]]= 1 
                
        hashmap= sorted(hashmap.items(), key =lambda x: x[1] ,reverse= True)

        print(hashmap)

        string= ""

        for key, value in hashmap:
            for i in range(0, value):
                string+= str(key)
        
        return string

            