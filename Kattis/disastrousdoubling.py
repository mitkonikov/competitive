n = int(input())
arr = list(map(int, input().rstrip().split(' ')))

MOD = 1000000007

bact = 2
error = False

for i in range(len(arr)):
    if (arr[i] > bact):
        print("error")
        error = True
        break

    bact = bact - arr[i]

    if i != len(arr) - 1:
        bact = bact * 2

if not error:
    print(bact % MOD)