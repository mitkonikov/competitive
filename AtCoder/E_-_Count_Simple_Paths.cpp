#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;

int ans = 0;

set<int> visited;

void dfs(int u) {
    ans++;
    if (ans >= 1000000) {
        cout << (int)1000000 << endl;
        exit(0);
    }
    
    visited.insert(u);
    for (auto v: adj[u]) {
        if (v == u) continue;
        if (visited.count(v)) continue;
        dfs(v);
    }
    visited.erase(u);
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}