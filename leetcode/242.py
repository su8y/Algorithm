""" 242. Valid Anagram https://leetcode.com/problems/valid-anagram/
map: defaultdict()를 통하여 wordcount, array보다 sc가 조금 높지만 의도가 명확하기 때문에 그대로 놔둠.
"""
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        wordCount: DefaultDict = defaultdict(int)

        # plus wordCount
        for ch in s:
            wordCount[ch] += 1

        # minus wordCount
        for ch in t:
            wordCount[ch] -= 1
        
        for count in wordCount.values():
            if count != 0: return False

        return True
