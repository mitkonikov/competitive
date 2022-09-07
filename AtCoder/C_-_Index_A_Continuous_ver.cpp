#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) pref[i] = pref[i-1] + a[i];
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans += (ll)(i+1) * a[i];
    }
    ll prev = ans;
    for (int i = m; i < n; i++) {
        ll cur_ans = prev + (m * a[i]) - a[i-m];
        cur_ans -= (pref[i-1] - pref[i-m]);
        prev = cur_ans;
        ans = max(ans, cur_ans);
    }
    cout << ans << endl;
    cout << flush;
    return 0;
}