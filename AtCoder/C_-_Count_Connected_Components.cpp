#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (auto v: adj[u]) {
        if (visited[v]) continue;
        dfs(v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    visited.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        count++;
        dfs(i);
    }
    cout << count << endl;
    return 0;
}