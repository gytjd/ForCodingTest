import sys
n=int(input())
stack=list()
for _ in range(n):
    contex=sys.stdin.readline().split()

    for i in contex:
        for j in range(len(i)):
            stack.append(i[j])
        for j in range(len(i)):
            print(stack.pop(),end="")

        print(end=" ")
    print()



