def geometric(n, b, m):
    T = 1
    e = b % m
    total = 0
    while n > 0:
        if n & 1 == 1:
            total = (e*total + T) % m
        T = ((e+1)*T) % m
        e = (e*e) % m
        n = n//2
    return total

k = list(map(int, input().split(' ')))
print(geometric(k[1], k[0], k[2]))
