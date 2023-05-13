import sys

n=int(sys.stdin.readline())
array=[list(map(int,sys.stdin.readline().split()))for i in range(n)]


def is_eqaul(x,y,n):
    first=array[x][y]

    for i in range(x,x+n):
        for j in range(y,y+n):
            if first!=array[i][j]:
                return 0
    return 1

minu_one_Count=0
zero_Count=0
one_Count=0

def color_paper(x,y,n):

    global minu_one_Count
    global zero_Count
    global one_Count
    if n==1:
        if array[x][y] == -1:
            minu_one_Count += 1
        elif array[x][y] == 0:
            zero_Count += 1
        elif array[x][y] == 1:
            one_Count += 1
        return

    if is_eqaul(x,y,n):
        if array[x][y]==-1:
            minu_one_Count+=1
        elif array[x][y]==0:
            zero_Count+=1
        elif array[x][y]==1:
            one_Count+=1
        return
    else:
        for i in range(x,x+n,n//3):
            for j in range(y,y+n,n//3):
                color_paper(i,j,n//3)


color_paper(0,0,n)
print(minu_one_Count)
print(zero_Count)
print(one_Count)