#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N, M;
    cin >> N >> M;
    if (M < N) {
        cout << 0 << endl;
        return;
    }
    
    ll k = 0, t = M;
    while (t) {
        t /= 2;
        k++;
    }

    ll L = M + 1;
    ll R = (1LL << (k + 1)) - 1;
    ll ans = N ^ L;
    ll x = L;
    auto ok = [&](ll n) {
        return (L <= n && n <= R);
    };
    for (int i = 30; i >= 0; i--) {
        if (ok((1LL << i) ^ x) && ((1LL << i) ^ ans) < ans) {
            ans ^= (1LL << i);
            x ^= (1LL << i);
        }
    }
    cout << ans << endl;
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