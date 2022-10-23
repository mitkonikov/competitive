import re

p = int(input())
n = int(input())
r, c = list(map(int, input().split(',')))
s = str(input())

mat = []
for i in range(r):
    mat.append([' ' for i in range(c)])

phrases = []
for i in range(p):
    x = input()
    phrases.append(x)

x = 0
y = 0

dict = { }

for i in range(n):
    newline = input()
    newline = re.sub("<[^>]+>", "", newline)
    if newline == "":
        continue

    for k in range(len(newline)):
        if x == r:
            break
        mat[x][y] = newline[k]
        
        if newline[k] in dict:
            if s == 'S':
                dict[newline[k]] = min(dict[newline[k]], (x, y))
            else:
                dict[newline[k]] = max(dict[newline[k]], (x, y))
        else:
            dict[newline[k]] = (x, y)

        y += 1
        if y == c:
            y = 0
            x += 1

for ph in phrases:
    ok = True
    ans = ""
    for i in range(len(ph)):
        if ph[i] not in dict:
            print(0)
            ok = False
            break
        
        ans += str(dict[ph[i]][0] + 1) + ","
        if i == len(ph) - 1:
            ans += str(dict[ph[i]][1] + 1)
        else:
            ans += str(dict[ph[i]][1] + 1) + ","
    if ok:
        print(ans)