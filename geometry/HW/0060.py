n = int(input())
x, y = map(int, input().split())
x1, y1, s = x, y, 0
for i in range(n - 1) :
    x2, y2 = map(int, input().split())
    s += (x1 + x2) * (y2 - y1)
    x1, y1 = x2, y2
    s += (x + x2) * (y - y1)
    print('%.3f' % (abs(s) / 2))