''' 875. Koko Eating Bananas '''
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        def check(x):
            nonlocal piles, h
            total = 0

            for pile in piles:
                d,m = divmod(pile, x)
                total += d
                if m != 0: 
                    total += 1
            return total <= h

        left, right = 0, 1_000_000_001

        while left + 1 < right:
            mid = (left + right) // 2
            if check(mid):
                right = mid
            else:
                left = mid

        if right == 1_000_000_001:
            return -1
        return right
