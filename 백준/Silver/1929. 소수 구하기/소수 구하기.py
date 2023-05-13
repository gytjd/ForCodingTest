import sys

n,m=map(int,sys.stdin.readline().split())
array=[i for i in range(m+1)]

for i in range(2,m+1):
    if array[i]==0:
        continue

    for j in range(2*i,m+1,+i):
        array[j]=0

for i in range(n,m+1):
    if i==1:
        continue
    else:
        if array[i] != 0:
            print(i)