''' 20. Valid Parentheses '''
class Solution:
    def isValid(self, s: str) -> bool:
        pair:dict = {
            "[": "]",
            "{": "}",
            "(": ")"
        }
        dq = deque()
        
        for ch in s:
            if ch in pair:
                dq.append(ch)
            else:
                if len(dq) <= 0 or pair[dq[-1]] != ch: return False
                dq.pop()
        return len(dq) == 0
        
