ans = 0
current = 0
while (True):
    try:
        k = input()
        if (k == ""):
            ans = max(ans, current)
            current = 0
            continue
        current += int(k)
    except:
        break
print(ans)