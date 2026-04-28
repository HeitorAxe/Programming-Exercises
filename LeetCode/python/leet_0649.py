class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        size = len(senate)
        dire_bans = 0
        radiant_bans = 0
        banned = [0]*size

        while True:
            for i in range(size):
                if banned[i] == 1:
                    continue
                if senate[i] == "R":
                    if radiant_bans > 0:
                        banned[i] = 1
                        radiant_bans-=1
                    else:
                        dire_bans+=1
                else:
                    if dire_bans > 0:
                        banned[i] = 1
                        dire_bans-=1
                    else:
                        radiant_bans+=1
            
            prev = ""
            flag_return = 1
            for i in range(size):
                if banned[i] == 0:
                    if prev == "":
                        prev = senate[i]
                    else:
                        if senate[i] != prev:
                            flag_return = 0
            if flag_return == 1:
                return "Radiant" if prev == "R" else "Dire"
