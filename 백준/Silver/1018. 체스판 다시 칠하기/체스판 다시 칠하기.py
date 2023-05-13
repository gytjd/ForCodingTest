import sys

n, m = map(int, sys.stdin.readline().split())
chess = list()

for _ in range(n):
    chess.append(sys.stdin.readline().strip())


def is_draw(temp, a, b):
    countA = 0
    countB =0

    if temp[a][b] == 'W':
        for i in range(a, a + 8, +2):
            for j in range(b, b + 7, +2):
                if temp[i][j] != 'W':
                    countA += 1
                else:
                    countB+=1

                if temp[i][j + 1] != 'B':
                    countA += 1
                else:
                    countB+=1

        for i in range(a + 1, a + 8, +2):
            for j in range(b, b + 7, +2):
                if temp[i][j] != 'B':
                    countA += 1
                else:
                    countB+=1
                if temp[i][j + 1] != 'W':
                    countA += 1
                else:
                    countB+=1
    else:
        for i in range(a, a + 8, +2):
            for j in range(b, b + 7, +2):
                if temp[i][j] != 'B':
                    countA += 1
                else:
                    countB+=1

                if temp[i][j + 1] != 'W':
                    countA += 1
                else:
                    countB+=1

        for i in range(a + 1, a + 8, +2):
            for j in range(b, b + 7, +2):
                if temp[i][j] != 'W':
                    countA += 1
                else:
                    countB+=1
                if temp[i][j + 1] != 'B':
                    countA += 1
                else:
                    countB+=1

    return min(countA,countB)

sum=1000

for i in range(n-8+1):
    for j in range(m-8+1):
        sum=min(sum,is_draw(chess,i,j))

print(sum)