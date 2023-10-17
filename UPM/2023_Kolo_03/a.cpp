#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
vector<vector<int>> adj;
vector<int> visited;
 
pair<bool, pair<int, int>> dfs(int u, int p = -1) {
    if (u == -1) return { true, { 100000, -100000 } };
    if (visited[u]) return { false, { 100000, -100000 } };
    visited[u] = true;
    auto L = dfs(adj[u][0], u);
    auto R = dfs(adj[u][1], u);
    bool ok = L.first & R.first;
    ok &= L.second.second < u;
    ok &= R.second.first > u;
    auto mn = min({ L.second.first, u, R.second.first });
    auto mx = max({ L.second.second, u, R.second.second });
    return { ok, { mn, mx }};
}
 
int main() {
    int N;
    cin >> N;
    adj.resize(N);
    visited.resize(N);
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[i].push_back(u);
        adj[i].push_back(v);
    }
    for (int i = 0; i < N; i++ ){
        fill(visited.begin(), visited.end(), 0);
        if (dfs(i).first) {
            bool ok = 1; 
            for (int i = 0; i < N; i++) {
                ok &= visited[i];
            }
            if (ok) {
                cout << "DA" << endl;
                return 0;
            }
        }
    }
    cout << "NE" << endl;
    return 0;
}