import heapq
t = int(input())
for _ in range(t):
    k = int(input())
    visitied = [False]*1000001
    min_heap,max_heap = [],[]
    for i in range(k):
        order,number = input().split()
        if order == 'I':
            heapq.heappush(min_heap,(int(number),i))
            heapq.heappush(max_heap,(-int(number),i))
            visitied[i] = True
        
        else:
            #최소힙구현
            if number == "-1":
                #큐에 들어있고 visitied가 False라면 max_heap에서 삭제된 원소
                while min_heap and not visitied[min_heap[0][1]]:
                    heapq.heappop(min_heap)
                if min_heap: #큐에 들어있는경우(visited = True)
                    visitied[min_heap[0][1]] = False
                    heapq.heappop(min_heap)
            #최대힙 구현
            if number == "1":
                #큐에 들어있고 visitied가 False라면 min_heap에서 삭제된 원소
                while max_heap and not visitied[max_heap[0][1]]:
                    heapq.heappop(max_heap)
                if max_heap:#큐에 들어있는 경우(visitied = True)
                    visitied[max_heap[0][1]] = False
                    heapq.heappop(max_heap)
    while min_heap and not visitied[min_heap[0][1]]:
        heapq.heappop(min_heap)
    while max_heap and not visitied[max_heap[0][1]]:
        heapq.heappop(max_heap)

    if len(min_heap)==0 or len(max_heap) == 0:
        print("EMPTY")
    else:
        print(-max_heap[0][0], min_heap[0][0])