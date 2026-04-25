class Solution:
    def reverseWords(self, s: str) -> str:
        l = s.split(" ")[::-1]
        fl = [item for item in l if item!=""]
        return " ".join(fl)