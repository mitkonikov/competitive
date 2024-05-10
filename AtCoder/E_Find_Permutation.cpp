#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<int> topo;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (auto v: adj[u]) {
        if (visited[v]) continue;
        dfs(v);
    }

    topo.push_back(u);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> P(M);
    adj.resize(N);
    visited.resize(N);
    vector<int> dp(N, 1);
    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        X--; Y--;
        P[i] = { X, Y };
        adj[Y].push_back(X);
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) dfs(i);
    }
    assert(topo.size() == N);
    for (int i = 0; i < N; i++) {
        int u = topo[i];
        for (auto v: adj[u]) dp[u] = max(dp[u], dp[v] + 1);
    }
    bool ok = *max_element(dp.begin(), dp.end()) == N;
    cout << (ok ? "Yes" : "No") << endl;
    if (ok) {
        for (auto el: dp) cout << el << " ";
        cout << endl;
    }
    return 0;
}