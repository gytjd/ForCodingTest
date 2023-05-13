import sys

n=int(input())
array=[list(map(int,sys.stdin.readline().split()))for i in range(n)]

def is_eqaul(x,y,idx_len):
    first=array[x][y]
    for i in range(x,x+idx_len):
        for j in range(y,y+idx_len):
            if first!=array[i][j]:
                return 0
    return 1

zero_Count=0
one_Count=0


def color_paper(dx,dy,idx):

    global zero_Count
    global one_Count

    if idx==1:
        if array[dx][dy] == 0:
            zero_Count += 1
        else:
            one_Count += 1

    else:
        if is_eqaul(dx,dy,idx):
             if array[dx][dy]==0:
                 zero_Count+=1
             else:
                 one_Count+=1

        else:
            color_paper(dx,dy,idx//2)
            color_paper(dx,dy+idx//2,idx//2)
            color_paper(dx+idx//2,dy,idx//2)
            color_paper(dx+idx//2,dy+idx//2,idx//2)


color_paper(0,0,n)

print(zero_Count)
print(one_Count)