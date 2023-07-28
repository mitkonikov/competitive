#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<ll> where(N, -1);
    vector<bool> visited(N);
    vector<vector<pair<ll, ll>>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        adj[u].push_back({ v, d });
        adj[v].push_back({ u, -d });
    }
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        queue<int> q;
        where[i] = 0;
        q.push(i);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            visited[t] = true;
            
            for (auto [v, d]: adj[t]) {
                if (!visited[v]) {
                    where[v] = where[t] + d;
                    q.push(v);
                    continue;
                }

                if (where[v] != where[t] + d) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}