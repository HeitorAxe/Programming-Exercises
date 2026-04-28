class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        frequence1 = [0]*26
        frequence2 = [0]*26
        for ch in word1:
            frequence1[ord(ch) - ord('a')] += 1
        for ch in word2:
            frequence2[ord(ch) - ord('a')] += 1

        for i in range(26):
            if (frequence1[i] == 0) != (frequence2[i] == 0):
                return False

        frequence1.sort()
        frequence2.sort()

        for i in range(26):
            if frequence1[i] != frequence2[i]:
                return False
        return True

