import sys

n = int(input())

for _ in range(n):
    sum = 0
    count=0
    array = list(map(int, sys.stdin.readline().split()))

    for i in range(1, array[0] + 1):
        sum += array[i]

    avg = sum / array[0]

    for i in range(1,array[0]+1):
        if array[i]>avg:
            count+=1

    result=count/array[0]*100
    print("{:.3f}%".format(result))
