#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) pref[i] = pref[i-1] + a[i];
    for (int i = 0; i < q; i++) {
        ll x;
        cin >> x;
        ll ans = 0;
        int id = lower_bound(a.begin(), a.end(), x) - a.begin();
        if (id == n) {
            ans = ((n * x) -  pref[n-1]);
        } else {
            ll countL = id;
            ll countR = n - countL;
            ll sumR = (pref[n-1] - (id - 1 >= 0 ? pref[id - 1] : 0));
            ans = ans + sumR - (countR * x);
            ans = ans + (countL * x) - (pref[n-1] - sumR);
        }
        cout << ans << endl;
    }
    cout << flush;
    return 0;
} 