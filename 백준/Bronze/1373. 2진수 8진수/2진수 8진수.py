context = input()

if len(context) % 3 == 2:
    context = '0' + context
elif len(context) % 3 == 1:
    context = '00' + context
else:
    context = context

for i in range(0, len(context), +3):
    exp = 2
    count = 0
    for j in range(i, i + 3, +1):
        if context[j] == '1':
            count += (2 ** exp)
        exp -= 1
    print(count, end="")
