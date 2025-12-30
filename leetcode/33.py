''' 33. Search in Rotated Sorted Array '''
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = -1, len(nums)-1

        while left + 1 < right:
            mid = int((left + right) / 2)
            
            if nums[mid] < nums[right]:
                right = mid
            else:
                left = mid

        def binary_search(left, right):
            nonlocal target
            while left <= right:
                mid = int((left + right) / 2)
                if nums[mid] == target:
                    return mid
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return -1
 
        res = binary_search(0, right - 1)
        if res != -1: return res
        
        return binary_search(right, len(nums) - 1) 

 
