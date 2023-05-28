#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> dp;
vector<vector<int>> adj;
vector<int> sz;

int dfs0(int u, int p = -1) {
    sz[u] = 1;
    for (auto v: adj[u]) {
        if (v == p) continue;
        sz[u] += dfs0(v, u);
    }
    return sz[u];
}

void dfs(int u, int p = -1) {
    vector<int> child;
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        child.push_back(v);
    }
    
    if (child.empty()) {
        dp[u][0] = 0;
        dp[u][1] = 0;
        return;
    }

    if (child.size() == 1) {
        dp[u][0] = max(dp[child[0]][0], dp[child[0]][1]);
    } else {
        dp[u][0] = max(dp[child[0]][0] + dp[child[1]][1], 
                       dp[child[0]][1] + dp[child[1]][0]);
    }

    dp[u][1] = sz[u] - 1;
}

void testCase() {
    int N;
    cin >> N;
    adj.clear();
    adj.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dp.clear();
    sz.clear();
    dp.resize(N, vector<int>(2, 0));
    sz.resize(N);
    dfs0(0);
    dfs(0);
    cout << dp[0][0] << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}