import sys

n = int(input())

array = list(map(int, sys.stdin.readline().split()))
result=set(array)
result=list(result)

result.sort()

temp=dict()
for i in range(len(result)):
    temp[result[i]]=i

for i in range(len(array)):
    print(temp[array[i]],end=" ")




