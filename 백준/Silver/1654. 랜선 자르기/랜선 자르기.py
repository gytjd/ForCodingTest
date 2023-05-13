import sys

k,m=map(int,sys.stdin.readline().split())
result=list()
for _ in range(k):
    result.append(int(input()))

start,end=1,max(result)

while start<=end:
    mid=(start+end)//2
    line_sum=0

    for i in result:
        line_sum+=i//mid

    if line_sum<m:
        end = mid - 1
    else:
        start=mid+1
print(end)