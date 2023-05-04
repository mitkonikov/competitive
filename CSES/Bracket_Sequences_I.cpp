#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll expo(ll b, ll e, ll m) {
    ll result = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            result = (result * b) % m;
            e--;
            continue;
        }

        b = (b * b) % m;
        e /= 2;
    }
    return result;
}

int main() {
    const int MX = 2e6 + 1e4;
    const int MOD = 1e9 + 7;
    vector<ll> fact(MX, 1), ifact(MX, 1);    
    for (int i = 1; i < MX; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    for (int i = 0; i < MX; i++) {
        ifact[i] = expo(fact[i], MOD - 2, MOD);
    }
    
    auto coeff = [&](ll N, ll K) {
        return (((fact[N] * ifact[K]) % MOD) * ifact[N-K]) % MOD;
    };

    int N;
    cin >> N;
    if (N % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    N /= 2;
    cout << (coeff(2 * N, N) - coeff(2 * N, N + 1) + MOD) % MOD << endl;
    return 0;
}