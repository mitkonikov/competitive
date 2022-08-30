#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int mxn = 1e5 + 100;

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> app(mxn, vector<ll>(5, 0));
    vector<vector<ll>> dp(mxn, vector<ll>(5, 0));
    for (int i = 0; i < n; i++) {
        ll t, x, a;
        cin >> t >> x >> a;
        app[t][x] += a;
    }
    dp[0][0] = app[0][0];
    for (int i = 1; i < mxn; i++) {
        for (int j = 0; j <= min(i, 4); j++) {
            for (int k = -1; k <= 1; k++) {
                if (j+k>=0 && j+k<5) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j+k] + app[i][j]);
                }
            }
        }
    }
    ll ans = 0;
    for (int j = 0; j < 5; j++) {
        ans = max(ans, dp[mxn-1][j]);
    }
    cout << ans << endl;
    cout << flush;
    return 0;
}