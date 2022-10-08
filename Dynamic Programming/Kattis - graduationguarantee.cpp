#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int offset = n + 4;
    vector<double> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.rbegin(), p.rend());

    double ans = (k == 1 ? p[0] : 0);
    vector<vector<double>> dp(n, vector<double>(2 * (n + 4), 0));

    dp[0][offset-1] = (1 - p[0]);
    dp[0][offset+1] = p[0];
    for (int i = 1; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < 2 * (n + 4); j++) {
            if (j-1>=0) dp[i][j] += dp[i-1][j-1] * p[i];
            if (j+1<2*(n+4)) dp[i][j] += dp[i-1][j+1] * ((double)1 - p[i]);
            if (j>=k+offset) sum += dp[i][j];
        }
        ans = max(ans, sum);
    }

    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}