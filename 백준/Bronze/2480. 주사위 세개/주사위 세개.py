a, b, c = map(int, input().split())


def is_eqaul(a, b, c):
    if a == b == c:
        return 10000 + a * 1000
    elif a == b:
        return 1000 + a * 100
    elif a == c:
        return 1000 + a * 100
    elif b == c:
        return 1000 + b * 100
    else:
        return max(a, b, c) * 100


print(is_eqaul(a, b, c))
