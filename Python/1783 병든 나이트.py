import sys

n, m = map(int, sys.stdin.readline().split())

if m >= 7:
    if n < 3:
        if n == 1:
            print(1)
        else:
            print(4)
    else:
        print(m - 1 - 6 + 5)
else:
    if n <= 4:
        if n == 1:
            print(1)
        elif n == 2:
            if m == 3 or m == 4:
                print(2)
            elif m == 5 or m == 6:
                print(3)
            else:
                print(1)
        else:
            if m <= 4:
                print(m)
            else:
                print(4)
    else:
        if m <= 4:
            print(m)
        else:
            print(4)

