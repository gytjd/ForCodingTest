a = int(input())
b = int(input())
c = int(input())

result = a * b * c
array = list(map(int, str(result)))
num = [0] * 10

for i in range(0, len(array)):
    num[array[i]] += 1
for i in range(10):
    print(num[i])
