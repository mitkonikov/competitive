#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

#define ll long long
// [start,end)
ll binary_search(function<bool(ll)> func, ll start, ll end) {
    /* func:int ->bool
        returns smallest int x where func(x) evaluates to true, searches in [start,end), it is assumed the values are false, .. , false, true ...
    */

    if (end <= start) return end;   // has to be here, otherwise func(end-1) in next line could be a problem
    if (!func(end-1)) return end;
    while (end - start > 1) {
        ll mid = (start + end) / 2;
        if (func(mid)) end = mid; else start = mid;
    }

    return (func(start) ? start : end);
};

int main() {
    int n;
    ll P, Q, R;
    cin >> n >> P >> Q >> R;

    ll sum = P + Q + R;
    vector<ll> a(n), pref(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + a[i];
    }

    auto binary = [&](int x, int R, ll sum) {
        int initR = R;
        ll cur_pref = (x-1>=0 ? pref[x-1] : 0);
        int id = binary_search([&](ll id) {
            return (pref[id] - cur_pref >= sum);
        }, x, R);
        if (pref[id] - cur_pref == sum && id + 1 < initR) {
            return id+1;
        }
        return -1;
    };

    bool ok = false;
    for (int x = 0; x < n-3; x++) {
        int w = binary(x, n, sum);
        if (w == -1) continue;
        int y = binary(x, w, P);
        if (y == -1) continue;
        int z = binary(y, w, Q);
        if (z == -1) continue;
        int ww = binary(z, w+1, R);
        if (ww == -1) continue;
        if (w == ww && x < y && y < z && z < w) {
            ok = true;
            // cout << x << " " << y << " " << z << " " << w << endl;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
    cout << flush;
    return 0;
}