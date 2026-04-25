from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        if len(nums) == 0:
            return 0
        product = 1
        zero_count = 0
        for x in nums:
            if x == 0:
                zero_count+=1
            else:
                product*=x
        
        new_list = []
        if zero_count==0:
            for x in nums:
                new_list.append((int)(product/x))
        elif zero_count==1:
            for x in nums:
                if x==0:
                    new_list.append(product)
                else:
                    new_list.append(0)
        elif zero_count>0:
            for x in nums:
                new_list.append(0)
                
        return new_list        