""" 238. Product of Array Except Self 
"""
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        answer = []
        for i in range(len(nums)): 
            productOfAll = 1
            for j in range(len(nums)):
                if i == j: continue;
                productOfAll *= nums[j]
            answer.append(productOfAll)
        return answer
