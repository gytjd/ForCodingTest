import sys

n = int(sys.stdin.readline())

queue = list()

for _ in range(n):
    context = sys.stdin.readline().split()

    if context[0] == "push":
        queue.append(context[1])

    elif context[0] == "front":

        if len(queue) == 0:
            print(-1)
        else:
            print(queue[0])

    elif context[0] == "back":

        if len(queue) == 0:
            print(-1)
        else:
            print(queue[-1])

    elif context[0] == "empty":

        if len(queue) == 0:
            print(1)
        else:
            print(0)

    elif context[0] == 'pop':

        if len(queue) == 0:
            print(-1)
        else:
            print(queue.pop(0))

    elif context[0] == 'size':

        print(len(queue))
