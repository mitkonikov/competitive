#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;

    if (b > (s/k)) {
        cout << -1 << endl;
        return;
    }

    bool ok = false;
    vector<ll> ans(n, 0);
    for (int diff = -1; diff < n-1; diff++) {
        if (diff >= 0) {
            ans[diff] = k-1;
            s -= k-1;
        }
        ans[n-1] = s;

        if ((s / k) == b) {
            ok = true;
            break;
        }
    }

    if (!ok) {
        cout << -1 << endl;
        return;
    }

    for (auto el: ans) {
        cout << el << " ";
    } cout << endl;
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