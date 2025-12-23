""" 217. Contains Duplicate https://leetcode.com/problems/contains-duplicate/description/
n = 10^5
bruteforce: O(n^2) 솔루션으로는 10^10이 되므로 시간복잡도 1초 10^8보다 큰 수치 이므로 TLE가 의심된다.
sorting: O(N*logN) 솔루션은 공간복잡도 O(1)으로 최적화를 할수 있지만 시간복잡도가 늘어나는 트레이드 오프
set: TC,SC = O(N)으로 이루어져 있다.
"""
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        sets:Set = set(nums)
        return len(sets) != len(nums)
        
