#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

ll safe_pow(ll a, ll b) {
    ll res = 1;
    for (ll i = 0; i < b; i++) {
        double dres = res;
        dres *= a;
        if (dres > 2e18) {
            return 2e18;
        }
        res *= a;
    }
    return res;
}

ll sqrt_floor(ll x) {
    ll l = 0, r = 2e9;
    while (l <= r) {
        ll t = (l + r) / 2;
        if (t * t > x) {
            r = t - 1;
        } else {
            l = t + 1;
        }
    }
    return r;
}

int main() {
    ll N;
    cin >> N;
    ll ans = sqrt_floor(N);
    set<ll> s;
    for (ll power = 3; power <= 60; power++) {
        for (ll base = 2;; base++) {
            ll r = safe_pow(base, power);
            if (r > N) {
                break;
            }
            ll ssq = sqrt_floor(r);
            if (ssq * ssq != r) {
                s.insert(r);
            }
        }
    }
    ans += s.size();
    cout << ans << endl;
    return 0;
}