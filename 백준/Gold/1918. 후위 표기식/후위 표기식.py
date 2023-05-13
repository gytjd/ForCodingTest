context = input()

stack = list()


def prec_word(a):
    if a == '(' or a == ')':
        return 0
    elif a == '+' or a == '-':
        return 1
    elif a == '*' or a == '/':
        return 2
    return -1


for i in context:
    if i == '+' or i == '-' or i == '*' or i == '/':
        while stack and prec_word(stack[-1]) >= prec_word(i):
            print(stack.pop(), end="")

        stack.append(i)
    elif i=='(':
        stack.append(i)
    elif i==')':
        open_ch=stack.pop()

        while open_ch!='(':
            print(open_ch,end="")
            open_ch=stack.pop()

    else:
        print(i, end="")

while stack:
    print(stack.pop(),end="")