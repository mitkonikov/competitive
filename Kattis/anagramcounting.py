from math import factorial

while True:
    try:
        k = input()
        ans = factorial(len(k))
        for letter in set(k):
            ans = ans // factorial(k.count(letter))
        print(ans)
    except:
        break