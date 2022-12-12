#include <bits/stdc++.h>
#define ll long long

using namespace std;

void testCase() {
    ll k, x;
    cin >> k >> x;

    ll ans = 0;
    ll full = k * (k+1) / 2;
    if (x > full) {
        ans += k;
        x -= full;
    } else if (x == full) {
        cout << k << endl;
        return;
    } else {
        ans += (-1LL + sqrt(1LL + 8 * (x-1))) / 2 + 1;
        cout << ans << endl;
        return;
    }

    k--;
    ll C = k * (k+1) / 2;
    if (x >= C) {
        cout << 2LL * (k+1) - 1 << endl;
        return;
    }

    ll m = (-1LL + sqrt(1LL + 8 * (C-x))) / 2;
    cout << ans + (k - m) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}