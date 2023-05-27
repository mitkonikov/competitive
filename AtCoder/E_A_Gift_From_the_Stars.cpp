#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;
vector<int> deg;

void dfs(int u, int p = -1, int leaf = true) {
    if (!leaf && !visited[u]) {
        ans.push_back(deg[u]);
        for (auto v: adj[u]) {
            visited[v] = true;
        }
        for (auto v: adj[u]) {
            if (v == p) continue;
            dfs(v, u, false);
        }
        visited[u] = true;
        return;
    }

    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u, !leaf);
    }
}

int main() {
    int N;
    cin >> N;
    deg.resize(N);
    adj.resize(N);
    visited.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for (int i = 0; i < N; i++) {
        if (deg[i] == 1) {
            dfs(i);
            break;
        }
    }
    sort(ans.begin(), ans.end());
    for (int el: ans) cout << el << " ";
    cout << endl;
    return 0;
}