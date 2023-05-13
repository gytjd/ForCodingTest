import sys

n, m = map(int, sys.stdin.readline().split())

queue = list()

for i in range(1, n + 1):
    queue.append(i)

i =0

result = list()

while len(queue):
    i = (i + (m-1)) % n

    result.append(str(queue.pop(i)))
    n-=1


print("<", ", ".join(result)[:], ">", sep='')

