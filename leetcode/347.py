"""
347. Top K Frequent Elements

solution: T,S

idea: 
    1. nums를 정렬후 최빈값 indices를 만든 후 k개 만큼 추출
    2. nums를 iterate하며 최빈값 배열 cnt를 만듦
        - cnt를 통하여 최빈값 indices를 만든후 k개만큼 추출
    bruteforce: 
"""
from collections import *
from typing import *
from functools import *


class Solution:
    # nums를 정렬후 최빈값 indices를 만든 후 k개 만큼 추출
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        answer = []
        sortedArr = sorted(nums)
        start = 0
        N = len(nums)

        for i in range(N + 1):
            if i == N or sortedArr[start] != sortedArr[i]:
                if i > start:
                    answer.append((-(i - start), sortedArr[start]))
                start = i 

        answer.sort()
        result = []
        for i in range(0, k):
            result.append(answer[i][1])

            
        return result
                    
