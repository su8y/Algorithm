""" 271. Encode and Decode Strings
encode: 문자열길이#원본문자열 
decode: 원본문자열
"""
class Solution:

    def encode(self, strs: List[str]) -> str:
        answer = ""
        for str in strs:
            answer += f"{len(str)}#{str}"
        return answer

    def decode(self, s: str) -> List[str]:
        answer = list()
        N = len(s)
        start = 0
        for i in range(N):
            if i > start and not '0' <= s[i] <= '9':
                wordLen = int(s[start:i]) # encode된 문자열 길이
                nextLenIndex = i+1+wordLen
                answer.append(s[i+1: nextLenIndex])
                start = nextLenIndex
                i = nextLenIndex
        return answer
