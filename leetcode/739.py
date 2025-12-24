''' 739. Daily Temperatures
1. BF[O(N^2) O(1)] 2 반복문으로 i에서 arr[j] > arr[i] 구함
2. STACK[O(N)] 괄호 체크를 확장하여 문제를 품.
  - 현재 넣으려고 하는 값보다 작은 값들에 대해서 index를 갱신해주면 되는문제 
  - if cur > stack[-1] 일때 넣음 index 값 기억하고 있어야함.

'''
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]: # O(N)
        stack: deque = deque() # [temper, index]
        answer = [0] * len(temperatures)

        for i in range(len(temperatures)):
            curT = temperatures[i]

            # 작은 값 제외 하며 갱신처리
            while stack and stack[-1][0] < curT:
                topT, topI = stack[-1]; 
                answer[topI] = i - topI
                stack.pop()

            stack.append((curT, i)) 

        # 마지막 갱신 처리 생략가능 이미 0으로 초기화되어있음
        # while stack:
        #     topT, topI = stack[-1]; 
        #     answer[topI] = 0
        #     stack.pop()
        
        return answer


    ''' 1-1 
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]: # O(N^2)
        cache = [[] for _ in range(101)]
        answer = [9_999_999_999] * len(temperatures)
        for i in range(len(temperatures)): 
            cache[temperatures[i]].append(i)

        for i in range(len(temperatures)): # O(N)
            curTemper = temperatures[i]
            # 현재 온도보다 높은 온도 캐시를 탐색
            for nextTemper in range(curTemper+1, 101): # O(1)
                for c in cache[nextTemper]: # O(N)
                    if c > i and answer[i] > c-i: # compare index
                        answer[i] = c-i
            if answer[i] == 9_999_999_999:
                answer[i] = 0

        return answer
    '''

    ''' 1
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        N = len(temperatures)
        answer = [0] * N
        for i in range(N):
            for j in range(i + 1, N):
                if temperatures[j] > temperatures[i]:
                    answer[i] = j - i
                    break
        return answer
    '''

