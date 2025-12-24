""" 15. 3Sum
"""
class Solution:
    """ Two Pointer O(N^2) """
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        target = 0
        nums.sort()
        N = len(nums)

        if N < 3:
            return []
        
        answer: set[tuple[int]] = set()
        for i in range(0, N):
            left, right = i + 1, N-1
            
            while left < right:
                cur = nums[left] + nums[right] + nums[i]
                if cur == target:
                    answer.add(tuple([nums[left] , nums[right] , nums[i]]))

                if cur <= target: 
                    left += 1
                else:
                    right -= 1

        return list(answer)


    
    """ brute force O(N^3)
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # sort Arr
        nums.sort()
        N = len(nums)

        if N < 3:
            return []
        
        answer: set[tuple[int]] = set()
        for i in range(0, N):
            for j in range(i+1, N):
                for k in range(j+1, N):
                    if nums[i] + nums[j] + nums[k] == 0:
                        answer.add(tuple([nums[i] , nums[j] , nums[k]]))
        return list(answer)
    """
