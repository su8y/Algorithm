class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        import collections

        nums_map = collections.defaultdict(list)

        for i, num in enumerate(nums):
            nums_map[num].append(i)

            if len(nums_map[num]) >= 2:
                output = abs(nums_map[num][-2] - i)
                if output <= k:
                    return True
        return False

