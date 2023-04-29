#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, p;
    cin >> n >> p;

    ll ans = 0;
    vector<vector<ll>> a(n + 1, vector<ll>(p, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> a[i][j];
        }

        sort(a[i].begin(), a[i].end());
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = min({ dp[i-1][1] + abs(a[i-1].back() - a[i].back()), 
                         dp[i-1][0] + abs(a[i-1].front() - a[i].back()) });

        dp[i][1] = min({ dp[i-1][0] + abs(a[i-1].front() - a[i].front()),
                         dp[i-1][1] + abs(a[i-1].back() - a[i].front()) });

        dp[i][0] += a[i].back() - a[i].front();
        dp[i][1] += a[i].back() - a[i].front();
    }

    cout << min(dp[n][0], dp[n][1]) << endl;
}

int main() {
    int t;
    cin >> t;

    for (int tt = 0; tt < t; tt++) {
        cout << "Case #" << tt + 1 << ": ";
        testCase();
    }

    cout << flush;
    return 0;
}