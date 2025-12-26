''' 853. Car Fleet '''
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        # sort car fleet
        sortedCarFleet = [(p,s) for p, s in zip(position, speed)]
        sortedCarFleet.sort(reverse=True)

        # move car & out car fleet
        stack = []
        for p, s in sortedCarFleet:
            stack.append((target - p) / s)

            if len(stack) >= 2 and stack[-1] <= stack[-2]:
                stack.pop()
        return len(stack)
