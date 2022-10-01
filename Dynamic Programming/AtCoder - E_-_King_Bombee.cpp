#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;
    int MOD = 998244353;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dp[k+1][n+1][2];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n+1; j++) {
            for (int rep = 0; rep < 2; rep++) {
                dp[i][j][rep] = 0;
            }
        }
    }
    dp[0][s][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto v: adj[j]) {
                if (j == x) {
                    dp[i][j][0] = ((ll)dp[i][j][0] + dp[i-1][v][1]) % MOD;
                    dp[i][j][1] = ((ll)dp[i][j][1] + dp[i-1][v][0]) % MOD;
                } else {
                    dp[i][j][0] = ((ll)dp[i][j][0] + dp[i-1][v][0]) % MOD;
                    dp[i][j][1] = ((ll)dp[i][j][1] + dp[i-1][v][1]) % MOD;
                }
            }
        }
    }
    cout << dp[k][t][0] << endl;
    return 0;
}