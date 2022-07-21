#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> recStack;
vector<bool> visited;
vector<bool> is_cycle;

bool dfs(int node) {
    recStack[node] = true;
    if (!visited[node]) {
        visited[node] = true;
        for (auto u: adj[node]) {
            if (!visited[u] && dfs(u)) {
                is_cycle[u] = true;
                return true;
            } else if (recStack[u]) {
                is_cycle[u] = true;
                return true;
            }
        }
    }

    recStack[node] = false;
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    adj.resize(n);
    visited.resize(n, false);
    recStack.resize(n, false);
    is_cycle.resize(n, false);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                is_cycle[i] = true;
            }
        }
    }

    int count = accumulate(is_cycle.begin(), is_cycle.end(), 0);
    cout << count << endl;
    return 0;
}