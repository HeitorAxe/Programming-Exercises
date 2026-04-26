class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        lenNums = len(nums)
        if lenNums in (0, 1):
            return 0

        zeros = 0
        maxSize = 0
        lastZero = -1
        p1 = 0
        p2 = 1

        if nums[p1] == 0:
            zeros+=1

        while True:
            
            if nums[p2] == 0:
                #if zeros == 0:
                zeros+=1
            if zeros <=1:
                maxSize = max(maxSize, p2-p1)

            if zeros >= 2:
                if nums[p1] == 0:
                    if p1+1<p2:
                        p1+=1
                        zeros-=1
                        while p1<p2-1:
                            if nums[p1]==1:
                                break
                            p1+=1
                            zeros-=1
                        
                elif nums[p1] == 1:
                    while p1<p2-1:
                        if nums[p1] == 0:
                            while p1<p2-1:
                                if nums[p1]==1:
                                    break
                                p1+=1
                                zeros-=1

                            break
                        else:
                            p1+=1
                    
            if p2>=lenNums-1:
                if zeros <= 1:
                    maxSize = max(maxSize, p2-p1)
                break
            p2+=1

                
        
        return maxSize
        