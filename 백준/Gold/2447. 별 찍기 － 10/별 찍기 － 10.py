import sys

n=int(sys.stdin.readline())

asterisk=[["*" for i in range(n)]for i in range(n)]

def display(n):
    for i in range(n):
        for j in range(n):
            print(asterisk[i][j], end="")

        print()

def print_blank(x,y,n):
    for i in range(x,x+n):
        for j in range(y,y+n):
            asterisk[i][j]=" "

def print_start(x,y,n):
    asterisk[x+1][y+1]=" "

def print_asterisk(x,y,n):

    if n==3:
        print_start(x,y,n)
        return

    for i in range(x,x+n,+n//3):
        for j in range(y,y+n,+n//3):
            if i==0 or j==0:
                print_asterisk(i, j, n // 3)
            else:
                if (i%n)==n//3 and (j%n)==n//3:
                    print_blank(i, j, n // 3)
                else:
                    print_asterisk(i, j, n // 3)

print_asterisk(0,0,n)
display(n)