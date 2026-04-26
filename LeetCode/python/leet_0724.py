from typing import List


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        l = []
        lr = []
        s = 0
        for i in nums[::-1]:
            lr.append(s)
            s+=i
        lr = lr[::-1]
        s = 0
        for i in nums:
            l.append(s)
            s+=i

        for i in range(len(nums)):
            if lr[i] == l[i]:
                return i
        
        return -1