import sys


n = int(input())
array = list(map(int, sys.stdin.readline().split()))


k = -1
m=0

for i in range(len(array) - 1):
    if array[i] < array[i + 1]:
        k = i

if k == -1:
    print(-1)
else:

    for j in range(k+1,len(array)):
        if array[k]<array[j]:
            m=j

    array[k],array[m]=array[m],array[k]

    temp=array[k+1:]
    temp.sort()
    array=array[:k+1]+temp

    print(*array)



