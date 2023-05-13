import sys
from collections import deque

n = int(sys.stdin.readline())
graph = [list(map(int, sys.stdin.readline().split())) for i in range(n)]

dir = [[0, 1], [1, 0], [0, -1], [-1, 0]]

shark_queue = deque()

current_size = 2
level = 0
total_result = 0


def shark_BFS():
    while shark_queue:
        x, y = shark_queue.popleft()
        visited[x][y] = 1

        for i in range(4):
            dx = x + dir[i][0]
            dy = y + dir[i][1]

            if dx < 0 or dx >= n or dy < 0 or dy >= n:
                continue

            if graph[dx][dy] <= current_size and visited[dx][dy] == 0:
                visited[dx][dy] = 1
                dir_cost[dx][dy] = dir_cost[x][y] + 1
                shark_queue.append((dx, dy))

                if graph[dx][dy] != 0 and graph[dx][dy] < current_size:
                    shark_eat.append((dir_cost[dx][dy], dx, dy))


for i in range(n):
    for j in range(n):
        if graph[i][j] == 9:
            graph[i][j] = 0
            shark_queue.append((i, j))

while True:
    shark_eat = list()
    visited = [[0 for i in range(n)] for i in range(n)]
    dir_cost = [[0 for i in range(n)] for i in range(n)]

    shark_BFS()

    if shark_eat:
        shark_eat.sort()
        shark_queue.append((shark_eat[0][1], shark_eat[0][2]))
        graph[shark_eat[0][1]][shark_eat[0][2]] = 0
        total_result += shark_eat[0][0]
        level += 1

        if current_size == level:
            current_size += 1
            level = 0

    else:
        print(total_result)
        break
