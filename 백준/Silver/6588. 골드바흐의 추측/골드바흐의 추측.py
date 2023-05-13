import sys


array=[i for i in range(1000001)]


for i in range(2,1000001):
    if array[i]==0:
        continue

    for j in range(2*i,1000001,+i):
        array[j]=0

while True:
    n=int(sys.stdin.readline())
    if n==0:
        break

    for i in range(2,n):
        if array[i]!=0 and array[n-i]!=0:
            print(f"{n} = {i} + {n-i}")
            break

