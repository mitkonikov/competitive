// Task: https://mendo.mk/Task.do?id=454

#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> rating;
vector<vector<int>> adj;
vector<vector<int>> dp;

void dfs(int u) {
    for (auto v: adj[u]) {
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
    dp[u][1] += rating[u];
}

int main() {
    int n;
    cin >> n;
    rating.resize(n);
    adj.resize(n);
    dp.resize(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
        int rat, p;
        if (i == 0) {
            cin >> rat;
            rating[i] = rat;
        } else {
            cin >> rat >> p;
            rating[i] = rat;
            adj[p].push_back(i);
        }
    }
    dfs(0);
    cout << max(dp[0][0], dp[0][1]) << endl;
    return 0;
}