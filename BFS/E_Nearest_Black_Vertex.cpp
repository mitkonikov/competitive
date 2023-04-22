#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj;

int main() {
    int N, M;
    cin >> N >> M;
    adj.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int K;
    cin >> K;
    vector<bool> paint(N, 0);
    vector<int> dist(N, INT_MAX / 2);
    vector<pair<int, int>> queries(K);
    for (int i = 0; i < K; i++) {
        int s, d;
        cin >> s >> d;
        s--;
        queries[i] = { s, d };

        fill(dist.begin(), dist.end(), INT_MAX / 2);
        queue<int> q;
        dist[s] = 0;
        if (d != 0) q.push(s);
        while (!q.empty()) {
            auto top = q.front();
            if (dist[top] < d) paint[top] = 1;
            q.pop();

            for (auto v: adj[top]) {
                if (dist[v] > dist[top] + 1) {
                    dist[v] = dist[top] + 1;
                    q.push(v);
                }
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < K; i++) {
        auto [s, d] = queries[i];
        fill(dist.begin(), dist.end(), INT_MAX / 2);
        queue<int> q;
        dist[s] = 0;
        q.push(s);
        int ans = INT_MAX;
        while (!q.empty()) {
            auto top = q.front();
            if (paint[top] == 0) ans = min(ans, dist[top]);
            q.pop();

            for (auto v: adj[top]) {
                if (dist[v] > dist[top] + 1) {
                    dist[v] = dist[top] + 1;
                    q.push(v);
                }
            }
        }
        if (ans != d) ok = false;
    }

    if (!ok) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    for (int i = 0; i < N; i++) {
        cout << (paint[i] ^ 1);
    }
    cout << endl;

    return 0;
}