import sys

# counting sort에서 빈도 저장하기 위한 배열
li = [0 for _ in range(10001)]

N = int(sys.stdin.readline())

# 인풋으로 받은 수가 몇변 들어왔는지 빈도 저장
for _ in range(N):
    num = int(sys.stdin.readline())
    li[num] += 1

# 배열의 시작부터 돌며 저장된 빈도만큼 인덱스값을 출력
for i in range(1, 10001):
    count = li[i]
    for _ in range(count):
        print(i)