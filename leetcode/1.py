from collections import *
from typing import *
from functools import *

"""
1. Two Sum
T,S
bruteforce: O(N^2), O(1)
map: O(N)
"""
class Solution:
    # bruteforce
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # given
        # when
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]

        # then
        return [-1, -1]
    """ map
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # given
        ma: DefaultDict = defaultdict(int)
        for i, num in enumerate(nums):
            ma[num] = i
        
        # when
        for i, num in enumerate(nums):
            diff: int = target - num
            if diff in ma and i != ma[diff]:
                return [min(i, ma[diff]), max(i, ma[diff])]

        # then
        return [-1, -1]
    """
