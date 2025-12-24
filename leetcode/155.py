''' 155. Min Stack
여러개의 스택 자료구조를 사용해서 고정된 크기일때 Min, Max을 구하는 테크닉: O(1), O(N)
BF: O(N)
'''
class MinStack:

    def __init__(self):
        self.stack = deque()
        self.minStack = deque()
        

    def push(self, val: int) -> None:
        self.stack.append(val)
        minTop = self.getMin()
        if minTop == None:
            self.minStack.append(val)
        else:
            self.minStack.append(min(val, minTop))

    def pop(self) -> None:
        self.stack.pop()
        self.minStack.pop()
        

    def top(self) -> int:
        if not self.stack: return None
        return self.stack[-1] 
        

    def getMin(self) -> int:
        if not self.minStack: return None
        return self.minStack[-1]
''' brute force
class MinStack:

    def __init__(self):
        self.stack = deque()
        

    def push(self, val: int) -> None:
        self.stack.append(val)

    def pop(self) -> None:
        self.stack.pop()
        

    def top(self) -> int:
        return self.stack[-1] 
        

    def getMin(self) -> int:
        return min(self.stack)
'''
