class Solution:
    def reverseVowels(self, s: str) -> str:
        stack = []
        newWord = ""
        for i in s:
            if i.upper() in ("A", "E", "I", "O", "U"):
                stack.append(i)
        for i in s:
            if i.upper() in ("A", "E", "I", "O", "U"):
                newWord += stack.pop()
            else:
                newWord+=i

        return newWord