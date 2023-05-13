import sys

while True:
    result = list(map(int, sys.stdin.readline().split()))

    if result[0]==0 and result[1]==0 and result[2]==0:
        break

    temp=max(result)
    result.remove(temp)

    sum=0
    for i in result:
        sum+=i*i

    if temp*temp==sum:
        print("right")
    else:
        print("wrong")
