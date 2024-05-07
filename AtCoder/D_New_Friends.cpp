#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        queue<int> q;
        q.push(i);
        set<int> vertices;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            vertices.insert(t);
            for (auto v: adj[t]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        ll V = vertices.size();
        ll E = 0;
        for (auto v: vertices) E += adj[v].size();
        E /= 2;
        ll complete = V * (V - 1) / 2;
        ans += complete - E;
    }
    cout << ans << endl;
    return 0;
}