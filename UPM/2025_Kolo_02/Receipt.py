ls = []
 
try:
 
    counter = 0
    while True:
        k = input()
        arr = k.split('\t')
        name = arr[0]
        price = arr[1]
        if ',' in price:
            s = price.split(",")
            while len(s[1]) < 2:
                s[1] += '0'
            price = s[0] + "," + s[1]
        else:
            price = price + ",00"
        ls.append([name, price, counter])
        counter += 1
    
except:
    
    max_len = max(len(x[0]) for x in ls)
    for i in range(len(ls)):
        ls[i][0] = ls[i][0] + ''.join('.' for x in range(max_len - len(ls[i][0])))
    max_len_price = max(len(x[1]) for x in ls)
    for i in range(len(ls)):
        ls[i][1] = ''.join(' ' for x in range(max_len_price - len(ls[i][1]))) + ls[i][1]
 
    ls.sort(key=lambda x: (x[1], -x[2]))
    ls.reverse()
 
    for i in range(len(ls)):
        print(f'{ls[i][0]} {ls[i][1]}')
 
    exit()