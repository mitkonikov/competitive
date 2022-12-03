current = 0
ls = []
while (True):
    try:
        k = input()
        if (k == ""):
            ls.append(current)
            current = 0
            continue
        current += int(k)
    except:
        break

print(sum(sorted(ls)[-3:]))