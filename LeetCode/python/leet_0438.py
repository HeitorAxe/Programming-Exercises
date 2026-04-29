from typing import List


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        p1 = 0
        p2 = len(p) - 1
        lenS = len(s)
        arr = []

        oc = dict()
        oc2 = dict()
        for c in p:
            if oc.get(c):
                oc[c] += 1
            else:
                oc[c] = 1

        if p2 < len(s):
            for i in range(p1, p2+1):
                if oc2.get(s[i]):
                    oc2[s[i]] += 1
                else:
                    oc2[s[i]] = 1
        else:
            return []
            
        while p2< lenS:

            isFit = True
            for key in oc:
                if oc[key] != oc2.get(key, -1):
                    isFit = False
            if isFit:
                arr.append(p1)

            p1+=1
            p2+=1

            if p2<lenS:
                if oc2.get(s[p2]):
                    oc2[s[p2]]+=1
                else:
                    oc2[s[p2]]=1

                oc2[s[p1-1]]-=1
            else:
                break
            
        return arr

