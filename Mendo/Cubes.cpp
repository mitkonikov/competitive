// Task: https://mendo.mk/Task.do?id=288

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    for (int i = 0; i < 3; i++) {
        dp[i][0] = 1;
    }
    for (int i = 3; i <= n; i++) {
        dp[i][1] = dp[i-3][0] + dp[i-1][1];
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
    }
    cout << dp[n][0] + dp[n][1] << endl;
    return 0;
}