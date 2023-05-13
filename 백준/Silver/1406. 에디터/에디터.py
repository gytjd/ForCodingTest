import sys

context = input()
stack = list()

for i in range(len(context)):
    stack.append(context[i])

n = int(input())

curr = len(context)
temp = list()
result = list()

for _ in range(n):
    command = sys.stdin.readline().split()

    if command[0] == 'P':
        stack.append(command[1])
        curr += 1

    elif command[0] == 'L':
        if curr == 0:
            curr = 0
        else:

            temp.append(stack.pop())
            curr -= 1

    elif command[0] == 'D' and temp:

        stack.append(temp.pop())
        curr += 1

    elif command[0] == 'B':

        if curr == 0:
            curr = 0
        else:
            stack.pop()
            curr -= 1

for i in stack:
    print(i, end="")

temp.reverse()

for i in temp:
    print(i, end="")

