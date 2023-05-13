import sys

n,m=map(int,sys.stdin.readline().split())
array=["B" for i in range(n)]

max_value=0
for i in range(1,n+1):
    if max_value<=((n-i)*i):
        max_value=(n-i)*i


if m<n:
    array[n-m-1]="A"
else:
    if m>max_value:
        print(-1)
        exit(0)
    else:
        temp_value = 2
        array[0] = "A"
        temp = n - temp_value

        while True:

            if m > temp * temp_value:
                array[temp_value - 1] = "A"
                temp_value += 1
                temp = n - temp_value
            else:
                array[(temp * temp_value) - m + (temp_value-1)] = "A"
                break

for i in array:
    print(i,end="")















