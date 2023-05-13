import sys

n = int(input())

queue = list()

for _ in range(n):
    command = sys.stdin.readline().split()

    if command[0] == "push_front":
        queue.insert(0, command[1])
    elif command[0] == "push_back":

        queue.append(command[1])

    elif command[0] == "pop_front":

        if len(queue) == 0:
            print(-1)
        else:
            print(queue.pop(0))

    elif command[0] == "pop_back":

        if len(queue) == 0:
            print(-1)
        else:
            print(queue.pop())

    elif command[0] == "size":

        print(len(queue))

    elif command[0] == "empty":

        if len(queue) == 0:
            print(1)
        else:
            print(0)

    elif command[0] == "front":

        if len(queue) == 0:
            print(-1)
        else:
            print(queue[0])

    elif command[0] == "back":

        if len(queue) == 0:
            print(-1)
        else:
            print(queue[-1])
