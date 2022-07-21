#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    ll L = 0, R = 1e9 + 10000;
    while (R - L > 1) {
        ll mid = (L + R) / 2;

        ll addTimes = 0;
        ll MIN = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            ll cur = v[i];
            if (cur >= mid) {
                ll diff = cur - mid;
                cur -= (diff / b) * b;
                addTimes -= (diff / b);
            } else {
                ll diff = mid - cur;
                ll curTimes = (diff / a + (diff % a != 0));
                cur += curTimes * a;
                addTimes += curTimes;
            }

            MIN = min(MIN, cur);
        }

        if (addTimes <= 0 && MIN >= mid) {
            L = mid;
        } else {
            R = mid;
        }
    }

    cout << L << endl;
    cout << flush;
    return 0;
}