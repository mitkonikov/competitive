#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> pref(n, vector<int>(63, 0));
    for (int i = 0; i < 62; i++) {
        pref[0][i] = ((a[0] & (1LL << i)) > 0);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 62; j++) {
            pref[i][j] = pref[i-1][j] + ((a[i] & (1LL << j)) > 0);
        }
    }
    for (int i = 0; i < q; i++) {
        int k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        l1--; r1--; l2--; r2--;
        ll range1_on = pref[r1][k] - (l1-1>=0 ? pref[l1-1][k] : 0);
        ll range2_on = pref[r2][k] - (l2-1>=0 ? pref[l2-1][k] : 0);
        ll range1_off = (r1 - l1 + 1) - range1_on;
        ll range2_off = (r2 - l2 + 1) - range2_on;
        ll ans = range1_on * range2_off + range1_off * range2_on;
        cout << ans << endl;
    }
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