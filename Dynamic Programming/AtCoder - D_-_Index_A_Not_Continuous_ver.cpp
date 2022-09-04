#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<ll>> dp(n, vector<ll>(m, LLONG_MIN + 1e9));
    dp[0][0] = a[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < min(m, i+1); j++) {
            dp[i][j] = max(dp[i-1][j], (j-1>=0 ? dp[i-1][j-1]:0) + ((ll)(j+1) * a[i]));
        }
    }
    ll ans = LLONG_MIN;
    for (int i = 0; i < n; i++) ans = max(ans, dp[i][m-1]);
    cout << ans << endl;
    cout << flush;
    return 0;
}