import sys

n,m=map(int,sys.stdin.readline().split())
wood=list(map(int,sys.stdin.readline().split()))

start,end=1,max(wood)

while start<=end:

    mid=(start+end)//2
    wood_len=0

    for i in wood:
        if i>mid:
            wood_len+=i-mid

    if wood_len>=m:
        start=mid+1
    else:
        end=mid-1

print(end)