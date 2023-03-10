#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

pair<int, int> dfs(int u, int p) {
    visited[u] = true;
    pair<int, int> ans = { 1, adj[u].size() };
    for (auto v: adj[u]) {
        if (v == p || visited[v]) continue;
        auto f = dfs(v, u);
        ans.first += f.first;
        ans.second += f.second;
    }
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    adj.resize(N);
    visited.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ok = true;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            auto ans = dfs(i, -1);
            ok &= (ans.first == ans.second / 2);
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
