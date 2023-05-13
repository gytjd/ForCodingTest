import sys

from collections import Counter

n = int(sys.stdin.readline())
array = [0 for _ in range(n)]
for i in range(n):
    array[i] = int(sys.stdin.readline())


def center_num(arr):
    arr.sort()
    print(arr[n // 2])


def count_num(arr):
    temp=Counter(arr).most_common(2)

    if len(temp)>1:
        if temp[0][1]==temp[1][1]:
            print(temp[1][0])
        else:
            print(temp[0][0])
    else:
        print(temp[0][0])


print(round(sum(array) / n))
center_num(array)
count_num(array)
print(max(array) - min(array))
