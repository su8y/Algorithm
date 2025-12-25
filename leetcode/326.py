''' 326. Power of Three '''
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        number = 3

        if n == 1: return True
        if n < 3: return False

        while number < 2_200_000_000:
            if number == n: return True
            number = number * 3

        return False   
