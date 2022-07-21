t = int(input())

def mapping(x):
    if x == "upper":
        return '0'
    elif x == "middle":
        return '1'
    else:
        return '2'

while t > 0:
    n = int(input())
    
    result = [[] for i in range(n)]

    longest = 0
    for i in range(n):
        entry = input().split(' ')
        var = entry[0][:-1]
        classes = list(map(mapping, entry[1].split('-')))
        addResult = ''.join(reversed(classes))
        result[i] = [addResult, var]
        longest = max(longest, len(addResult))
    
    for i in range(n):
        result[i][0] = result[i][0] + ''.join(['1' for i in range(longest - len(result[i][0]))])

    result.sort()

    for i in range(n):
        print(result[i][1])

    t -= 1
    print("==============================")
