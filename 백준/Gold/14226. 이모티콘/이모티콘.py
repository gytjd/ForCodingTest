from collections import deque
n=int(input())

queue=deque()
queue.append((1,0,0))

visited=[[0 for i in range(1001)]for i in range(1001)]


while queue:
    a,b,count=queue.popleft()

    if a==n:
        print(count)
        break

    for i in range(3):
        if i==0:
            x=a
            y=a

            if x<=1000 and visited[x][y]==0:
                visited[x][y]=1
                queue.append((x, y, count + 1))

        elif i==1:

            if b == 0:
                continue
            else:
                x = a + b
                y = b

                if x<=1000 and visited[x][y]==0:
                    visited[x][y]=1
                    queue.append((x, y, count + 1))

        else:
            x=a-1
            y=b

            if x==0:
                continue
            else:
                if x<=1000 and visited[x][y]==0:
                    visited[x][y]=1
                    queue.append((x, y, count + 1))





