class Solution:
    def decodeString(self, s: str) -> str:
        i = 0
        return self.decode(s, i)[0]
        
    def decode(self, s: str, i: int):
        lenS = len(s)
        mul = 0
        num = ""
        result = ""
        while i<lenS:
            if s[i].isnumeric():
                num+=s[i]
                i+=1
            elif s[i] == "[":
                i+=1
                decodedList = self.decode(s, i)
                decoded = decodedList[0]
                i = decodedList[1]
                result += decoded*(int(num))
                num = ""
                
            elif s[i] == "]":
                i+=1
                return [result, i]
            else:
                result+=s[i]
                i+=1
        return [result, i]

