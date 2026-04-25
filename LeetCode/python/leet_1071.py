class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        gcd = ""
        prefix = ""
        if min(len(str1), len(str2)) == len(str1):
            prefix = str1
        else:
            prefix = str2
        
        while True:
            divides1 = True
            divides2 = True
            print(prefix)
            
            i = 0
            while True:
                if i+len(prefix)<= len(str1) and prefix == str1[i:i+len(prefix)]:
                    i+=len(prefix)
                else:
                    divides1 = False
                    break
                if i==len(str1):
                    break
            i = 0
            while True:
                if i+len(prefix)<=len(str2) and prefix == str2[i:i+len(prefix)]:
                    i+=len(prefix)
                else:
                    divides2 = False
                    break
                if i==len(str2):
                    break

            if divides1 == False or divides2 == False:
                prefix=prefix[:-1]
            else:
                return prefix
            
            if prefix == "":
                return ""
        

            


                    
