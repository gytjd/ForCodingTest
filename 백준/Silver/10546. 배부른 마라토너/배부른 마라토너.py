import sys
from collections import Counter

n=int(sys.stdin.readline())
temp=list()

for _ in range(n+n-1):
    temp.append(sys.stdin.readline().rstrip())

temp=Counter(temp)

for i in temp.items():
    if i[1]%2!=0:
        print(i[0])
        break

