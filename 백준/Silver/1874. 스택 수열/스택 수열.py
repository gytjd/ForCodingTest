n = int(input())

array = list()
stack = list()

result = list()
top = 1

for _ in range(n):
    array.append(int(input()))

for i in range(n):

    while top <= array[i]:
        stack.append(top)
        top += 1
        result.append("+")

    if stack[-1] == array[i]:
        stack.pop()
        result.append("-")
    else:
        break

if stack:
    print("NO")
else:
    for i in result:
        print(i)
