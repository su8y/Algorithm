''' 150. Evaluate Reverse Polish Notation
'''
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:

        st: Deque = deque()
        for token in tokens:
            newNum:int = None
            if token == '+': 
                newNum = int(st[-2]) + int(st[-1])
            elif token == '-':
                newNum = int(st[-2]) - int(st[-1])
            elif token == '*':
                newNum = int(st[-2]) * int(st[-1])
            elif token == '/':
                newNum = int(int(st[-2]) / int(st[-1]))
            else: 
                st.append(int(token))
                continue
            st.pop()
            st.pop()

            if newNum != None:
                st.append(newNum)
        return int(st[-1])
