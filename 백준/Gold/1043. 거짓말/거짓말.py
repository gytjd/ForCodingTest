import sys

n,m=map(int,sys.stdin.readline().split())
knowTrue=set(map(int,sys.stdin.readline().split()[1:]))

party=[set(map(int,sys.stdin.readline().split()[1:])) for i in range(m)]

for _ in range(m):
    for j in party:
        if j & knowTrue:
            knowTrue = knowTrue.union(j)

count=0

if knowTrue:
    for i in party:
        if i & knowTrue:
            continue
        count += 1

    print(count)
else:
    print(m)


