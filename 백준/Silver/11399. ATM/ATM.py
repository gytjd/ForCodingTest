import sys

n=int(input())
array=list(map(int,sys.stdin.readline().split()))
array.sort()

result_sum=0
for i in range(n):
    sum=0
    for j in range(i+1):
        sum+=array[j]
    result_sum+=sum

print(result_sum)