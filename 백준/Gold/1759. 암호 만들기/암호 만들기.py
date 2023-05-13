import sys
from itertools import combinations

n,m=map(int,sys.stdin.readline().split())
alpha=list(map(str,sys.stdin.readline().split()))
alpha.sort()

temp=list(combinations(alpha,n))

for i in temp:
    mo_count = 0
    ja_count = 0

    for j in i:
        if j=='a' or j=='e' or j=='i' or j=='o' or j=='u':
            mo_count+=1
        else:
            ja_count+=1


    if mo_count>=1 and ja_count>=2:
        for k in i:
            print(k,end="")
        print()


