def comb(n, k):
    res = 1
    k = min(k, n - k)
    for i in range(1, k + 1):
        res = res * (n - k + i) // i
    return res

n, s = map(int, input().split())
res = 0
for i in range(n // 2):
    res += comb(s - 2 + i, s - 2)
res = comb(n + s - 1, s - 1) - s * res
print(res)
