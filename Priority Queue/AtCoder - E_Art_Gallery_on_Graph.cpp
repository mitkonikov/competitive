#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    adj.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int, int>> guards(K);
    for (int i = 0; i < K; i++) {
        cin >> guards[i].first >> guards[i].second;
        guards[i].first--;
    }
    vector<int> power(N, -1);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < K; i++) {
        pq.push({ guards[i].second, guards[i].first });
        power[guards[i].first] = guards[i].second;
    }
    while (!pq.empty()) {
        auto [p, v] = pq.top();
        pq.pop();
        if (power[v] > p) continue;
        for (auto u: adj[v]) {
            if (power[u] < power[v] - 1) {
                power[u] = power[v] - 1;
                pq.push({ power[u], u });
            }
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (power[i] > -1) count++;
    }
    cout << count << endl;
    for (int i = 0; i < N; i++) {
        if (power[i] > -1) cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
}