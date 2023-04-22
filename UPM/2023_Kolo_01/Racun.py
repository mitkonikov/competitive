dict = {}
dict[1001] = 349
dict[1002] = 79
dict[1003] = 299
dict[1004] = 200
dict[1005] = 189
dict[1006] = 499
dict[1007] = 1149
dict[1008] = 700
dict[1009] = 129
dict[1010] = 99
dict[1011] = 29
dict[1025] = 159
dict[1036] = 199
dict[1049] = 249
dict[1068] = 159
dict[1075] = 229
dict[1082] = 179
dict[1091] = 149
dict[1106] = 399
dict[1123] = 329
dict[1144] = 499
dict[1177] = 349
dict[1208] = 199
dict[1243] = 449
dict[1280] = 229
dict[1331] = 299
dict[1396] = 149
dict[1458] = 99
dict[1525] = 79
dict[1597] = 249
dict[1674] = 179
dict[1760] = 599
dict[1855] = 949
dict[1959] = 579
dict[2075] = 349
dict[2110] = 499
dict[2199] = 249
dict[2237] = 199
dict[2291] = 849
dict[2349] = 249
dict[2411] = 179
dict[2477] = 249
dict[2539] = 149
dict[2610] = 349
dict[2713] = 129
dict[2834] = 199
dict[2977] = 349
dict[3126] = 499
dict[3187] = 149
dict[3251] = 599
dict[3320] = 200
dict[3468] = 199
dict[3534] = 49
dict[3672] = 1099
dict[3746] = 349
dict[3855] = 149
dict[3975] = 249
dict[4099] = 1500
dict[4177] = 1399
dict[4291] = 199
dict[4333] = 299
dict[4422] = 449
 
sum = 0
 
while True:
    try:
        article = input()
        if (article[0] == '-'):
            break
        article = article.split(' ')
        sum += dict[int(article[0])] * int(article[1])
    except:
        break
 
card = input()
if card == "CASH":
    if (sum % 5 <= 2):
        sum -= sum % 5
    else:
        sum += 5 - (sum % 5)
 
a = str(sum)[:-2]
if len(a) == 0:
    a = '0'
print(a + '.' + str(sum)[-2:])