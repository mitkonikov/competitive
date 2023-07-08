// This solves the E2 version as well.

#include <bits/stdc++.h>
#define ll __int128_t
#define endl '\n'

using namespace std;

bool over(ll a, ll x) {
    if (x != 0 && a > ((ll)1 << 126) / x) return true; // `a * x` would overflow
    // if (x != 0 && a < -((ll)1 << 125) / x) return true; // `a * x` would underflow
    return false;
}

pair<bool, ll> binary(ll base, ll power) {
    ll result = 1;

    while (power > 0) {
        if (power % 2 == 1) {
            if (over(result, base)) return { 0, 0 };
            result = result * base;
            power--;
            continue;
        }

        if (over(base, base)) return { 0, 0 };
        base = base * base;
        power /= 2;
    }

    return { 1, result };
}

void testCase() {
    // f(k, 0) = 1 + k + k * k => sqrt(k)
    // f(k, 1) = f(k, 0) + k^3
    // f(k, 2) = f(k, 1) + k^4 = f(k, 0) + k^3 + k^4
    // f(k, 2 + i) = f(k, 0) + sum from j=3 to j=4+i of k^j
    
    // f(k, n) = k^0 + k^1 + k^2 + k^3 + k^4 + ... k^n = (k^(1 + n) - 1) / (k - 1)
    // N = (k^(1 + n) - 1) / (k - 1)
    // N * (k - 1) = k ^ (1 + n) - 1
    // N * (k - 1) + 1 = k ^ (1 + n)

    ll N;
    long long NN;
    cin >> NN;
    N = NN;

    for (ll n = 2; n < 60; n++) {
        double nth = pow(NN, (double)1 / n);
        ll Lk = 1, Rk = min(1e9+100, nth * nth);
        while (Rk - Lk > 1) {
            ll M = (Rk + Lk) / 2;
            auto kn1 = binary(M, n + 1);
            if (kn1.first == 0) {
                Rk = M;
            } else {
                if (N * (M - 1) < kn1.second - 1) {
                    Rk = M;
                } else if (N * (M - 1) == kn1.second - 1) {
                    cout << "YES" << endl;
                    return;
                } else {
                    Lk = M;
                }
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}