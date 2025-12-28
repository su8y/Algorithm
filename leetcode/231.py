''' 231. Power of Two '''
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        for i in range(0, 32):
            if (1 << i) == n:
                return True
        
        return False
        
