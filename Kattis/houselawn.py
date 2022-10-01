l, n = list(map(int, input().split(' ')))
ans = []
for i in range(n):
    name, p, c, t, r = input().split(',')
    p, c, t, r = list(map(int, [p, c, t, r]))
    it = 10080 / (t + r)
    if (c * t * it >= l):
        ans.append((p, i, name))

if len(ans) == 0:
    print('no such mower')
else:
    ans.sort()
    print(ans[0][2])
    for i in range(1, len(ans)):
        if ans[i][0] == ans[0][0]:
            print(ans[i][2])
