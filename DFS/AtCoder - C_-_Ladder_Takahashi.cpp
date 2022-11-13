#include <bits/stdc++.h>
#define ll long long

using namespace std;

map<int, vector<int>> adj;
map<int, bool> visited;
int ans = 1;

void dfs(int u) {
    visited[u] = true;
    ans = max(ans, u);
    for (auto v: adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}