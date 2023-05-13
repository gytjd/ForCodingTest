import sys

ax, ay, az, bx, by, bz, cx, cy, cz = map(int, sys.stdin.readline().split())


def calculate(x1, y1, z1, x2, y2, z2):                              # 두 점 사이의 거리 계산
    return ((x2-x1)**2 + (y2-y1)**2 + (z2-z1)**2) ** (1/2)


minlen = 1e9
lenSC = calculate(ax, ay, az, cx, cy, cz)
lenEC = calculate(bx, by, bz, cx, cy, cz)

while 1:
    mx = (ax + bx) / 2
    my = (ay + by) / 2
    mz = (az + bz) / 2
    lenKC = calculate(mx, my, mz, cx, cy, cz)           # mid(임의의 점)과 C 사이의 거리
    if abs(minlen - lenKC) <= 1e-6:
        print('{:.10f}'.format(lenKC))
        break
    minlen = min(lenKC, minlen)
    if lenSC < lenEC:              						# [시작점과 C 사이의 거리]가 [끝점과 C 사이의 거리]보다 작을때, 끝점을 시작점쪽으로 당기기
        bx, by, bz = mx, my, mz
        lenEC = lenKC
    else:
        ax, ay, az = mx, my, mz
        lenSC = lenKC