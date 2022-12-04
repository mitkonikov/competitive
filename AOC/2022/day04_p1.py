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
        if x >= a and x <= b and y >= a and y <= b:
            ans += 1
        elif a >= x and a <= y and b >= x and b <= y:
            ans += 1
    except:
        break
print(ans)