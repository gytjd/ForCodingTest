import sys

n=int(sys.stdin.readline())

temp_sum=0
for i in range(1,n+1):
    temp_sum+=i*(n//i)

print(temp_sum)
