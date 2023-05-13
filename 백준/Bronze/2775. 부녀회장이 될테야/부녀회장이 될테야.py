n=int(input())

for _ in range(n):
    first=int(input())
    second=int(input())

    floor=[[i for i in range(1,second+1)]for i in range(first+1)]

    for i in range(1,first+1):
        for j in range(second):
            sum = 0
            for k in range(j+1):
                sum+=floor[i-1][k]
            floor[i][j]=sum

    print(floor[first][second-1])








