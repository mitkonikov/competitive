#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    ll ans = sum;
    vector<ll> left_dp(n), right_dp(n+1);
    vector<ll> left_min_dp(n, LLONG_MAX), right_min_dp(n, LLONG_MAX);
    for (int i = 0; i < n; i++) {
        left_dp[i] = i-1>=0 ? left_dp[i-1] : 0;
        left_dp[i] += (l - v[i]);
        left_min_dp[i] = min((i-1>=0 ? left_min_dp[i-1] : LLONG_MAX), left_dp[i]);
    }
    for (int i = n-1; i>=0; i--) {
        right_dp[i] = i+1<n ? right_dp[i+1] : 0;
        right_dp[i] += (r - v[i]);
        right_min_dp[i] = min((i+1<n ? right_min_dp[i+1] : LLONG_MAX), right_dp[i]);
    }
    for (int i = n; i >= 0; i--) {
        ans = min(ans, sum + (i-1>=0 ? left_min_dp[i-1] : 0) + (i<n ? right_min_dp[i] : 0));
    }
    cout << ans << endl;
    cout << flush;
    return 0;
}