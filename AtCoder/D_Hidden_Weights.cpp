#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N);
    vector<ll> ans(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, -w });
    }
    vector<bool> visited(N);
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        ans[i] = 0;
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            for (auto& [v, w] : adj[top]) {
                if (!visited[v]) {
                    ans[v] = ans[top] + w;
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}