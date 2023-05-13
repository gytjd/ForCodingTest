context = input()

stack = list()

inStack = 0

for i in range(len(context)):

    if context[i] == "<":
        if len(stack) != 0:
            while stack:
                print(stack.pop(), end="")

        stack.append(context[i])
        inStack = 1

    if context[i] == ">":
        stack.append(context[i])

        open_ch = stack.pop(0)

        while open_ch != ">":
            print(open_ch, end="")
            open_ch = stack.pop(0)
        print(">", end="")
        inStack = 0

    if context[i] == " " and inStack == 0:
        while stack:
            print(stack.pop(), end="")
        print(end=" ")
    if context[i] != "<" and context[i] != ">":
        if context[i]==" ":
            if inStack==1:
                stack.append(context[i])
        else:
            stack.append(context[i])

while stack:
    print(stack.pop(), end="")