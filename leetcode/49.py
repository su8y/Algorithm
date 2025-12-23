"""
49. Group Anagrams
T,S
bruteforce: 
"""
from collections import *
from typing import *
from functools import *


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        answer: List[List[str]] = []
        ma: DefaultDict = defaultdict(list)
        
        for word in strs:
            cntArr = [0] * 26
            for ch in word:
                cntArr[ord(ch) - ord('a')] += 1
            ma[tuple(cntArr)].append(word)


        for lst in countMap.values():
            answer.append(lst)

        return answer
        
