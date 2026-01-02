''' 567. Permutation in String ''' 
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        count = [0] * 26
        
        for c in s1:
            count[ord(c) - ord('a')] += 1
        
        tmp = [0] * 26
        cnt = 0
        for i in range(len(s2)):
            
            cnt += 1
            tmp[ord(s2[i]) - ord('a')] += 1
            if i > 0 and cnt > len(s1):
                cnt -= 1
                tmp[ ord(s2[i -  len(s1)]) - ord('a') ] -= 1

            if tmp == count: 
                return True
        
        return False
