""" 11. Container With Most Water """
class Solution:
    """ Tow Pointer
        높이가 낮은 쪽의 포인터를 고정한채 폭을 줄이면 면적은 절대 증가할수 없기때문에
        높이가 높은 쪽을 고정하여 낮은쪽의 포인터를 옮기는 그리디 방식
    """
    def maxArea(self, heights: List[int]) -> int:
        N = len(heights)
        maximum = 0
        
        left, right = 0, N-1
        while left < right:
            minH = min(heights[left], heights[right])
            w = right - left
            maximum = max(maximum, minH * w)

            if heights[left] < heights[right]:
                left += 1
            else:
                right -= 1
        

        return maximum
