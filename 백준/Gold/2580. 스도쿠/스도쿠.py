import sys

sdoku=list()

temp=list()

for _ in range(9):
    sdoku.append(list(map(int,sys.stdin.readline().split())))

for i in range(9):
    for j in range(9):
        if sdoku[i][j]==0:
            temp.append((i,j))

def check_col(x,a):
    for i in range(9):
        if sdoku[x][i]==a:
            return 0
    return 1


def check_row(y,a):
    for i in range(9):
        if sdoku[i][y]==a:
            return 0
    return 1

def check_square(x,y,a):
    dx=x//3*3
    dy=y//3*3

    for i in range(dx,dx+3):
        for j in range(dy,dy+3):
            if sdoku[i][j]==a:
                return 0
    return 1


def complete_sdoku(temp_num):

    if temp_num==len(temp):
        for i in sdoku:
            print(*i)
        exit()

    for i in range(1,10):
        nx=temp[temp_num][0]
        ny=temp[temp_num][1]

        if check_col(nx,i) and check_row(ny,i) and check_square(nx,ny,i):
            sdoku[nx][ny]=i
            complete_sdoku(temp_num+1)
            sdoku[nx][ny]=0

complete_sdoku(0)
