#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    vector<ll> pref(n); pref[0] = a[0];
    for (int i = 1; i < n; i++) pref[i] = pref[i-1] + a[i];
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        // cout << " > " << (x-1>=0 ? pref[x-1] : 0) << " " << (x-y >= 0 ? pref[x-y] : 0) << endl;
        ll all = (x-1>=0 ? pref[x-1] : 0) - (x-y-1 >= 0 ? pref[x-y-1] : 0);
        cout << all << endl;
    }
    cout << flush;
    return 0;
}