#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;
    vector<int> visited(n, 0);
    int iter = 1;
    for (int i = 0; i < q; i++) {
        queue<pair<int, int>> bfs;
        int x, k;
        cin >> x >> k;
        x--;
        k++;
        bfs.push({ x, 1 });
        int ans = 0;
        while (!bfs.empty()) {
            auto t = bfs.front();
            bfs.pop();
            ans += t.first + 1;
            visited[t.first] = iter;
            if (t.second + 1 <= k) {
                for (auto v: adj[t.first]) {
                    if (visited[v] < iter) {
                        visited[v] = iter;
                        bfs.push({ v, t.second + 1 });
                    }
                }
            }
        }
        iter++;
        cout << ans << endl;
    }

    cout << flush;
    return 0;
}