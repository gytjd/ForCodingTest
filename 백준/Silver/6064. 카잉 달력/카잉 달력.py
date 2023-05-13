import sys

n=int(sys.stdin.readline())

for _ in range(n):
    M, N, x, y = map(int, sys.stdin.readline().split())

    while x<=N*M:
        if x%N==y%N:
            print(x)
            break
        x+=M

    else:
        print(-1)


