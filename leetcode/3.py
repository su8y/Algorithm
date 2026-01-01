''' 3. Longest Substring Without Repeating Characters '''
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        mp = defaultdict()
        n = len(s)
        l, r = 0, 0

        while r < n:
            while mp.get(s[r], 0) != 0:
                mp[s[l]] = 0
                l += 1
            mp[s[r]] = mp.get(s[r], 0) + 1
            r += 1
            ans = max(ans, r - l)

        return ans
            
