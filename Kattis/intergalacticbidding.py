n, s = list(map(int, input().split(' ')))

lst = []

for i in range(n):
    name, bid = input().split(' ')
    bid = int(bid)
    lst.append([bid, name])

lst.sort()
lst.reverse()

sum = 0
ans = []
ANS = []
for i in range(n):
    if (sum + lst[i][0] <= s):
        sum += lst[i][0]
        ans.append(lst[i][1])

    if sum == s:
        ANS.extend(ans)
        ans = []
        sum = 0

print(len(ANS))
print('\n'.join(ANS))