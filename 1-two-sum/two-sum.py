class Solution(object):

    def twoSum(self, nums, target):

        hashmap= {}
        for key, value in enumerate(nums): 
            hashmap[value]= key 
        
        for i in range(0, len(nums)): 

            num = target - nums[i]
            if num in hashmap: 
                if i != hashmap[num]:
                    array=[]
                    array.append(i)
                    array.append(hashmap[num])
                    return array