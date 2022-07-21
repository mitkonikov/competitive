while True:
    try:
        a = list(map(int, input().split(' ')))
        print(abs(a[0] - a[1]))
    except:
        break