#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll n;
    cin >> n;
    vector<ll> a(n), pref(n);
    vector<bool> choose(n, false);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) choose[i] = true;
        if (i == 0) pref[i] = a[i];
        else pref[i] = pref[i-1] + a[i];
    }
    ll last_z = -1;
    map<ll, ll> frq;
    vector<ll> f(n, 0);
    for (ll i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (last_z != -1) {
                ll most_common = -1;
                ll el = -1;
                for (auto v: frq) {
                    if (v.second > most_common) {
                        most_common = v.second;
                        el = v.first;
                    }
                }
                f[last_z] = -el;
            }
            last_z = i;
            frq.clear();
        }
        frq[pref[i]]++;
    }

    if (last_z != -1) {
        ll most_common = -1;
        ll el = -1;
        for (auto v: frq) {
            if (v.second > most_common) {
                most_common = v.second;
                el = v.first;
            }
        }
        f[last_z] = -el;
    }

    ll count = 0;
    ll acc = 0;
    for (ll i = 0; i < n; i++) {
        if (choose[i]) {
            a[i] = f[i] - acc;
            acc += a[i];
        }
        if (i == 0) pref[i] = a[i];
        else pref[i] = pref[i-1] + a[i];
        if (pref[i] == 0) count++;
    }

    cout << count << endl;
}

int main() {
    ll t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}