from typing import List

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        ma = max(nums)
        mi = min(nums)
        mil = []
        mal = []
        count = 0
        for num in nums:
            mal.append(ma)
            ma = min(ma, num)
        for num in nums[::-1]:
            mil.append(mi)
            mi = max(mi, num)
        mil = mil[::-1]
        print(mal)
        print(mil)
        for i in range(len(nums)):
            if nums[i] > mal[i] and nums[i] < mil[i]:
                return True
        return False

        
