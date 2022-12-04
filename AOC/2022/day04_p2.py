ans = 0
while (True):
    try:
        ls = input().split(',')
        x, y = list(map(int, ls[0].split('-')))
        a, b = list(map(int, ls[1].split('-')))
        if y < x:
            x, y = y, x
        if b < a:
            a, b = b, a
        if (x <= b and y >= a) or (a >= y and b <= x):
            ans += 1
    except:
        break
print(ans)