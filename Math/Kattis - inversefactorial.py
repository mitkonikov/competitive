from cmath import log10
from math import floor
N = input()

fact = 1
for i in range(1, 11):
    fact *= i
    if str(fact) == N:
        print(i)
        exit(0)

l = len(N)
digits = len(str(fact))
ans = 11
while True:
    digits += abs(log10(ans))
    if floor(digits) + 1 >= l:
        print(ans)
        exit(0)
    ans += 1