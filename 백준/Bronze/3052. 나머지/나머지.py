array = list()
result = [0] * 42
count=0

for _ in range(10):
    array.append(int(input()))

for i in range(10):
    result[array[i] % 42] += 1

for i in range(42):
    if result[i]!=0:
        count+=1

print(count)
