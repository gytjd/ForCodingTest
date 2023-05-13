import sys

n,m=map(int,sys.stdin.readline().split())
graph=[list(map(int,sys.stdin.readline().split()))for i in range(n)]

def first():
    resultA=0
    resultB=0
    for i in range(n):
        for j in range(m-3):
            if resultA<graph[i][j]+graph[i][j+1]+graph[i][j+2]+graph[i][j+3]:
                resultA=graph[i][j]+graph[i][j+1]+graph[i][j+2]+graph[i][j+3]

    for i in range(n-3):
        for j in range(m):
            if resultB<graph[i][j]+graph[i+1][j]+graph[i+2][j]+graph[i+3][j]:
                resultB=graph[i][j]+graph[i+1][j]+graph[i+2][j]+graph[i+3][j]

    return max(resultA,resultB)


def Second():
    resultA=0
    resultB=0
    resultC=0
    resultD=0

    for i in range(n-2):
        for j in range(m-1):
            if resultA<graph[i][j]+graph[i+1][j]+graph[i+1][j+1]+graph[i+2][j+1]:
                resultA=graph[i][j]+graph[i+1][j]+graph[i+1][j+1]+graph[i+2][j+1]

    for i in range(n-2):
        for j in range(1,m):
            if resultB<graph[i][j]+graph[i+1][j]+graph[i+1][j-1]+graph[i+2][j-1]:
                resultB=graph[i][j]+graph[i+1][j]+graph[i+1][j-1]+graph[i+2][j-1]

    for i in range(1,n):
        for j in range(m-2):
            if resultC<graph[i][j]+graph[i][j+1]+graph[i-1][j+1]+graph[i-1][j+2]:
                resultC=graph[i][j]+graph[i][j+1]+graph[i-1][j+1]+graph[i-1][j+2]
    for i in range(n-1):
        for j in range(m-2):
            if resultD<graph[i][j]+graph[i][j+1]+graph[i+1][j+1]+graph[i+1][j+2]:
                resultD=graph[i][j]+graph[i][j+1]+graph[i+1][j+1]+graph[i+1][j+2]

    return max(resultA, resultB,resultC,resultD)

def Third():
    resultA=0

    for i in range(n-1):
        for j in range(m-1):
            if resultA<graph[i][j]+graph[i][j+1]+graph[i+1][j]+graph[i+1][j+1]:
                resultA=graph[i][j]+graph[i][j+1]+graph[i+1][j]+graph[i+1][j+1]

    return resultA

def Fourth():
    resultA=0
    resultB=0
    resultC=0
    resultD=0

    resultE=0
    resultF=0
    resultG=0
    resultH=0

    for i in range(n-2):
        for j in range(m-1):
            if resultA<graph[i][j]+graph[i+1][j]+graph[i+2][j]+graph[i+2][j+1]:
                resultA=graph[i][j]+graph[i+1][j]+graph[i+2][j]+graph[i+2][j+1]
    for i in range(n-2):
        for j in range(1,m):
            if resultB<graph[i][j]+graph[i+1][j]+graph[i+2][j]+graph[i+2][j-1]:
                resultB=graph[i][j]+graph[i+1][j]+graph[i+2][j]+graph[i+2][j-1]
    for i in range(n-2):
        for j in range(m-1):
            if resultC<graph[i][j]+graph[i][j+1]+graph[i+1][j]+graph[i+2][j]:
                resultC=graph[i][j]+graph[i][j+1]+graph[i+1][j]+graph[i+2][j]
    for i in range(n-2):
        for j in range(m-1):
            if resultD<graph[i][j]+graph[i][j+1]+graph[i+1][j+1]+graph[i+2][j+1]:
                resultD=graph[i][j]+graph[i][j+1]+graph[i+1][j+1]+graph[i+2][j+1]


    for i in range(n-1):
        for j in range(m-2):
            if resultE<graph[i][j]+graph[i][j+1]+graph[i][j+2]+graph[i+1][j]:
                resultE=graph[i][j]+graph[i][j+1]+graph[i][j+2]+graph[i+1][j]

    for i in range(1,n):
        for j in range(m-2):
            if resultF<graph[i][j]+graph[i][j+1]+graph[i][j+2]+graph[i-1][j+2]:
                resultF=graph[i][j]+graph[i][j+1]+graph[i][j+2]+graph[i-1][j+2]

    for i in range(n-1):
        for j in range(m-2):
            if resultG<graph[i][j]+graph[i+1][j]+graph[i+1][j+1]+graph[i+1][j+2]:
                resultG=graph[i][j]+graph[i+1][j]+graph[i+1][j+1]+graph[i+1][j+2]

    for i in range(n-1):
        for j in range(m-2):
            if resultH<graph[i][j]+graph[i][j+1]+graph[i][j+2]+graph[i+1][j+2]:
                resultH=graph[i][j]+graph[i][j+1]+graph[i][j+2]+graph[i+1][j+2]


    return max(resultA,resultB,resultC,resultD,resultE,resultF,resultG,resultH)

def Fifth():
    resultA=0
    resultB=0
    resultC=0
    resultD=0


    for i in range(n-1):
        for j in range(m-2):
            if resultA<graph[i][j]+graph[i][j+1]+graph[i][j+2]+graph[i+1][j+1]:
                resultA=graph[i][j]+graph[i][j+1]+graph[i][j+2]+graph[i+1][j+1]

    for i in range(n-1):
        for j in range(1,m-1):

            if resultB<graph[i][j]+graph[i+1][j-1]+graph[i+1][j]+graph[i+1][j+1]:
                resultB=graph[i][j]+graph[i+1][j-1]+graph[i+1][j]+graph[i+1][j+1]

    for i in range(1,n-1):
        for j in range(m-1):
            if resultC<graph[i][j]+graph[i-1][j+1]+graph[i][j+1]+graph[i+1][j+1]:
                resultC=graph[i][j]+graph[i-1][j+1]+graph[i][j+1]+graph[i+1][j+1]

    for i in range(n-2):
        for j in range(m-1):
            if resultD<graph[i][j]+graph[i+1][j]+graph[i+2][j]+graph[i+1][j+1]:
                resultD=graph[i][j]+graph[i+1][j]+graph[i+2][j]+graph[i+1][j+1]

    return max(resultA,resultB,resultC,resultD)

def start():
    a=first()
    b=Second()
    c=Third()
    d=Fourth()
    e=Fifth()

    print(max(a,b,c,d,e))

start()