class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        most_candies = max(candies)
        result = []
        for candy in candies:
            result.append(candy+extraCandies>=most_candies)
        return result