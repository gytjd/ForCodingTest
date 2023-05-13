import sys

n,m=map(int,sys.stdin.readline().split())
array=list(map(int,sys.stdin.readline().split()))
prefix_sum=[0]

temp=0
for i in array:
    temp+=i
    prefix_sum.append(temp)


for _ in range(m):
    sum=0
    start,end=map(int,sys.stdin.readline().split())
    print(prefix_sum[end]-prefix_sum[start-1])