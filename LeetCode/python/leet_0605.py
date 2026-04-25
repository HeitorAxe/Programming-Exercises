class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        can_plant = 0
        zeros = 1
        current = 0
        for i in flowerbed:
            if i == 0:
                zeros+=1
            else:
                can_plant+=current
                current = 0
                zeros = 0

            if zeros == 3:
                current=1
            elif zeros >= 3: 
                current = ((int)(zeros-3)/2)+1
        
        if zeros>=2:
            zeros+=1
            if zeros == 3:
                current=1
            elif zeros >= 3: 
                current = ((int)(zeros-3)/2)+1
            can_plant+=current

        return can_plant>=n
        
            

