#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, h;
    cin >> n >> h;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<vector<long long> > dp(n, vector<long long>(n));
    for (int l = 1; l <= n; l++) {
        for (int i = 0, j = l - 1; j < n; i++, j++) {
            if (l == 1) { dp[i][j] = h;continue; }
            int cut = max(0, h - (x[j] - x[i] - 1) / 2);
            dp[i][j] = dp[i][i] + dp[i + 1][j] - cut;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] - cut);
            }
        }
    }
    cout << dp[0][n - 1];
}