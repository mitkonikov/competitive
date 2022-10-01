#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const ll MOD = 1e9 + 7;

void testCase() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> mp(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]] = i;
    }

    ll L = mp[0], R = mp[0];
    ll ans = 1;
    for (int i = 1; i < n; i++) {
        if (mp[i] < L) {
            L = mp[i];
        } else if (mp[i] > R) {
            R = mp[i];
        } else if ((R - L - i + 1) > 1) {
            ans = (ans * (R - L - i + 1)) % MOD;
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