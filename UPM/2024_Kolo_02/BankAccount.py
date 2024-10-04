t = int(input())
def conv(s):
    if s >= 'A' and s <= 'Z':
        return str(ord(s) - ord('A') + 10)
    return str(s)
for i in range(t):
    bank = input()
    bank = bank.replace(' ', '')
    if (bank[:4] != "SI56"):
        print("NE")
        continue
    if (len(bank) != 19):
        print("NE")
        continue
    fail = False
    for k in bank[4:]:
        if not (k >= '0' and k <= '9'):
            fail = True
    if fail:
        print("NE")
        continue
 
    bank = bank[4:] + bank[:4]
    bank = list(map(str, bank))
    bank = ''.join(list(map(conv, bank)))
    result = int(bank) % 97
    if result == 1:
        print("JA")
    else:
        print("NE")
