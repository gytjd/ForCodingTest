import sys
from collections import deque

first = sys.stdin.readline().rstrip()
first_len = len(first)

last = sys.stdin.readline().rstrip()

queue = deque()
queue.append(last)

while queue:
    temp = queue.popleft()

    if len(temp) == first_len:
        if temp == first:
            print(1)
        else:
            print(0)
        break

    if temp[-1] == 'A':
        temp = temp[:-1]
        queue.append(temp)

    elif temp[-1] == "B":
        temp = temp[:-1]
        temp = temp[::-1]
        queue.append(temp)
