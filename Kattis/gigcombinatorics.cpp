#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = (int)1e9+7;

int main() {
    int n, x;
    scanf("%d", &n);

    ll ans = 0;
    ll ones = 0, twos = 0, threes = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        if (x == 1) {
            ones = (ones + 1) % MOD;
        } else if (x == 2) {
            twos = (((twos * 2) % MOD) + ones) % MOD;
        } else {
            ans = (ans + twos) % MOD;
        }
    }
 
    cout << ans << endl;
 
    return 0;
}