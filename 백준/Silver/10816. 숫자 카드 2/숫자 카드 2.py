import sys

n=int(input())
temp=list(map(int,sys.stdin.readline().split()))
temp.sort()

m=int(input())
temp2=list(map(int,sys.stdin.readline().split()))

result=dict()

for i in temp:
    if i not in result:
        result[i]=1
    else:
        result[i]=result[i]+1


for i in temp2:
    if i in result:
        print(result[i],end=" ")
    else:
        print(0,end=" ")
