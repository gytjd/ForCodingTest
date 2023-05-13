import sys

n=int(input())

array =list()

for _ in range(n):
    x,y=map(int,sys.stdin.readline().split())
    array.append((x,y))

array.sort()


for i in range(n):
    print(array[i][0],array[i][1])
