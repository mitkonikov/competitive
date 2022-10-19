#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (s[i] == '1') ans += a[i];
    }
    bool l = false;
    ll bal = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            l = true;
            bal = 0;
            continue;
        }

        if (l) {
            bal -= a[i];
            bal += a[i-1];
            if (bal > 0) {
                ans += bal;
                l = true;
                bal = 0;
                continue;
            }
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