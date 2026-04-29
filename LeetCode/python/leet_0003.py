class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        p1 = 0
        maxSize = 0
        lenS = len(s)
        while p1<lenS:
            repeated = set()
            counter = 0
            for i in range(p1, p1+128):
                if i < lenS:
                    if not s[i] in repeated:
                        repeated.add(s[i])
                        counter+=1
                    else:
                        break
            if counter > maxSize:
                maxSize = max(maxSize, counter)
            p1+=1
        return maxSize
