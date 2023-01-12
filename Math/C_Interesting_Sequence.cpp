#include <bits/stdc++.h>
#define u128 __uint128_t
#define ll long long
#define endl '\n'

using namespace std;

inline ll AND(ll n, ll m) {
    if (m == 0) {
        return 0;
    }
    ll result = 1;
    while (m != n) {
        m >>= 1;
        n >>= 1;
        result <<= 1;
    }
    return m * result;
}

void testCase() {
    ll N, X;
    cin >> N >> X;

    if (N < X) {
        cout << -1 << endl;
        return;
    }

    ll L = N;
    ll R = N;
    ll last_i = 0;
    for (int i = 0; i < 63; i++) {
        if ((1LL << i) & N) {
            last_i = i;
        }
    }

    R = (1LL << (last_i + 1));
    while (R - L > 1) {
        ll MID = L + (R - L) / 2;
        ll A = AND(N, MID);
        if (A > X) {
            L = MID;
        } else {
            R = MID;
        }
    }

    for (ll OFF = -10; OFF <= 10; OFF++) {
        if (L + OFF >= N && AND(N, L + OFF) == X) {
            cout << L + OFF << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}