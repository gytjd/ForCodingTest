n = int(input())

num = 1
count = 9
result = 0

while count < n:
    
    temp = count * num

    result += temp
    n -= count

    count *= 10
    num += 1


result = result + (n * num)

print(result)
