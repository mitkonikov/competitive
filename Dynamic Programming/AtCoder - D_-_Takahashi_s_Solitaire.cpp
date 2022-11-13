#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        a.push_back(a[i]);
    }
    vector<ll> dp(2 * n);
    dp[0] = a[0];
    ll best = a[0];
    for (int i = 1; i < a.size(); i++) {
        dp[i] = max(dp[i], (ll)a[i]);
        if (a[i] == a[i-1] || a[i] == ((a[i-1] + 1) % m)) {
            dp[i] = max(dp[i], dp[i-1] + a[i]);
        }
        best = max(best, dp[i]);
    }
    cout << max(0LL, sum - best) << endl;
    return 0;
}