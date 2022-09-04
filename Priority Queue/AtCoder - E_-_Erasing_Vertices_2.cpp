#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> costs(n);
    for (int i = 0; i < n; i++) cin >> costs[i];
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<bool> removed(n, false);
    auto sum = [&](int u) {
        ll res = 0;
        for (auto v: adj[u]) {
            if (removed[v]) continue;
            res += costs[v];
        }
        return res;
    };
    for (int i = 0; i < n; i++) {
        pq.push({ sum(i), i });
    }
    ll ans = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (removed[top.second]) {
            continue;
        }

        ans = max(ans, top.first);
        removed[top.second] = true;
        for (auto u: adj[top.second]) {
            if (removed[u]) continue;
            pq.push({ sum(u), u });
        }
    }
    cout << ans << endl;
    cout << flush;
    return 0;
}