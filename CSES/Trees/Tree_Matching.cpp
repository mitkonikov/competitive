#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj, dp;

void dfs(int u, int p = -1) {
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
    for (auto v: adj[u]) {
        if (v == p) continue;
        dp[u][1] = max(dp[u][1], dp[v][0] + 1 + dp[u][0] - max(dp[v][0], dp[v][1]));
    }
}

int main() {
    int N;
    cin >> N;
    adj.resize(N);
    dp.resize(N, vector<int>(2, 0));
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    cout << max(dp[0][0], dp[0][1]) << endl;
    return 0;
}