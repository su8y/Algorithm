import sys

N = int(sys.stdin.readline())
comparison = [0]
for i in range(N):
    comparison.append(int(sys.stdin.readline()))

answer = ""
stack = []
i, j = 1, 1
while(True):
    if i <= comparison[j]:
        answer += "+"
        stack.append(i)
        i += 1
    else:
        if stack[-1] == comparison[j]:
            stack.pop()
            answer += "-"
            j += 1
        else:
            print("NO")
            break
    
    if i==N+1 and j==N+1:
        for letter in answer:
            print(letter)
        break
