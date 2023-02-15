#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int dfs(int u) {
    int count = 1;
    visited[u] = true;
    for (auto v: adj[u]) {
        if (visited[v]) continue;
        count += dfs(v);
    }
    return count;
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
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        int v = dfs(i);
        count += v - 1;    
    }
    cout << M - count << endl;
    return 0;
}