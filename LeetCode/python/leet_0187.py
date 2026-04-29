from typing import List


class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        result = []
        occurs = set()
        lenS = len(s)
        p1 = 0
        p2 = 9
        while p2<lenS:
            chain = ""
            for i in range(p1, p2+1):
                chain+=s[i]
            if chain in occurs and not chain in result:
                result.append(chain)
            else:
                occurs.add(chain)
            p1+=1
            p2+=1
        return result