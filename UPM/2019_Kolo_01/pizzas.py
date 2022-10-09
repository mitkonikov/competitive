n, k = list(map(int, input().split()))

ans = 0
buy = []

for i in range(0, n):
    a = sorted(list(map(int, input().split())))
    buy.append(a[-1])

buy.sort()

for i in range(0, k):
    ans += buy[i]

print(ans)