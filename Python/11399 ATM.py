import sys

n=int(sys.stdin.readline())
array=list(map(int,sys.stdin.readline().split()))
array.sort()

result=0
for i in range(n):
    for j in range(i+1):
        result+=array[j]

print(result)

