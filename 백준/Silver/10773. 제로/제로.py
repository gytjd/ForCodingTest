n=int(input())

stack=list()

for _ in range(n):
    num=int(input())

    if num!=0:
        stack.append(num)
    else:
        stack.pop()


print(sum(stack))