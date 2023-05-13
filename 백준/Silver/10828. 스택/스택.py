import sys

n = int(input())
stack = list()

size = 0

for _ in range(n):
    contex=sys.stdin.readline().split()

    if contex[0] == "push":
        stack.append(contex[1])
        size += 1
    elif contex[0] == "top":
        if size == 0:
            print(-1)
        else:
            print(stack[size - 1])
    elif contex[0] == "size":
        print(size)
    elif contex[0] == "empty":
        if size == 0:
            print(1)
        else:
            print(0)
    elif contex[0] == "pop":
        if size == 0:
            print(-1)
        else:
            print(stack.pop())
            size -= 1
