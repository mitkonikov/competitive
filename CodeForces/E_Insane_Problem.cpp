#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll K, L1, R1, L2, R2;
    cin >> K >> L1 >> R1 >> L2 >> R2;
    ll ans = 0;
    for (ll k = 1; k <= R2; k *= K) {
        // k * x = y
        ll X1 = (L2 + k - 1) / k;
        ll X2 = R2 / k;
        X1 = max(X1, L1);
        X2 = min(X2, R1);
        if (X2 >= X1) {
            ans += X2 - X1 + 1;
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