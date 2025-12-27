''' 84. Largest Rectangle in Histogram '''
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        N,answer = len(heights), 0
        monotic = [] # (height, index)


        for i in range(N):
            curH = heights[i]

            curI = i
            while monotic and monotic[-1][0] > curH:
                prevH, prevI = monotic.pop()
                area = prevH *  (i - prevI) # h * w
                answer = max(answer, area)
                curI = prevI
            monotic.append((curH, curI))
        print(monotic)
        for i in range(len(monotic)):
            curH, curI = monotic[i]
            lastH, lastI = monotic[-1]

            answer = max(answer, curH * (N - curI))
        return answer



