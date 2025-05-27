class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """

        memoryList={}

        for word in strs:
            sortedword= ''.join(sorted(word))
            if sortedword not in memoryList:
                memoryList[sortedword]=[]
            memoryList[sortedword].append(word)
                

        returnList= []

        for value in memoryList.values():
            returnList.append(value)

        return returnList




            


        