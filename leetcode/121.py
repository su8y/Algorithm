''' 121. Best Time to Buy and Sell Stock '''
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        answer = 0
        minStack = []

        for price in prices:
            if minStack:
                answer = max(answer, price - minStack[-1])

            if minStack:
                minStack.append(min(minStack[-1], price))
            else:
                minStack.append(price)
            
        return answer
