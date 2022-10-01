#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct edge {
    ll u, v, c;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> dp(n, vector<ll>(n, (ll)1e9 + 100));
    for (int i = 0; i < n; i++) dp[i][i] = 0;
    vector<edge> edges(m);
    for (int i = 0; i < m; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        dp[u][v] = c;
        dp[v][u] = c;
        edges[i] = { u, v, c };
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        bool ok = false;
        for (int j = 0; j < n; j++) {
            if (edges[i].u == j || edges[i].v == j) continue;
            ok |= ((dp[edges[i].u][j] + dp[j][edges[i].v]) <= edges[i].c);
        }

        ans += ok;
    }
    
    cout << ans << endl;
    return 0;
}