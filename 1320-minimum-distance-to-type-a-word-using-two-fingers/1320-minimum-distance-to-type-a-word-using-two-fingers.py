class Solution:
    def minimumDistance(self, word: str) -> int:
        def moveCost(pos1,pos2):
            if pos1==-1 or pos2==-1:
                return 0
            x1,y1 = pos1//6, pos1%6
            x2,y2 = pos2//6, pos2%6
            return abs(x2-x1) + abs(y2-y1)

        @lru_cache(None)
        def minDist(pos1,pos2,curr_pos) -> int:
            if curr_pos >= len(word):
                return 0
            char_pos = ord(word[curr_pos])- 65
            move1 = moveCost(char_pos,pos1) + minDist(char_pos,pos2,curr_pos+1)
            move2 = moveCost(char_pos,pos2) + minDist(pos1,char_pos,curr_pos+1)
            return min(move1,move2)
        
        return minDist(-1,-1,0)