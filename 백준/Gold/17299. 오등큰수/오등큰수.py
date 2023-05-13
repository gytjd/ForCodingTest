import sys
from collections import Counter
n = int(input())

array = list(map(int, sys.stdin.readline().split()))
countResult = Counter(array)

stack = list()
result = [-1] * n

stack.append(0)
for i in range(1, n):
    while stack and countResult[array[stack[-1]]] < countResult[array[i]]:
        result[stack.pop()] = array[i]
    stack.append(i)

print(*result)
