import sys

n = int(input())

array = list()

for _ in range(n):
    array.append(sys.stdin.readline().split())

array.sort(key=lambda x: int(x[0]))

for i in array:
    print(*i)
