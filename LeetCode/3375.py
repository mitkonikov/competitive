def f(n, k):
    t = set(n)
    m = min(t)
    return -1 if m < k else len(t) - (m == k)
