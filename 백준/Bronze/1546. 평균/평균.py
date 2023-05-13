import sys

n = int(input())
array = list(map(int, sys.stdin.readline().split()))
sum = 0
max=max(array)

for i in range(n):
    array[i] = array[i] / max * 100
    sum += array[i]

print(sum / n)

