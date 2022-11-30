#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct dsu {
    vector<int> parent;

    dsu(int n) {
        parent.resize(n, -1);
    }

    int find_set(int a) {
        if (parent[a] < 0) return a;
        return parent[a] = find_set(parent[a]);
    }

    int merge(int a, int b) {
        int x = find_set(a), y = find_set(b);
        if (x == y) return x;
        if (-parent[x] < -parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        return x;
    }

    bool are_same(int a, int b) {
        return find_set(a) == find_set(b);
    }

    int size(int a) {
        return -parent[find_set(a)];
    }
};

vector<vector<int>> adj;
vector<int> edges;
vector<bool> visited;

void dfs(int u, int p, dsu& d, int k) {
    edges[k] += (int)adj[u].size();
    visited[u] = true;
    for (auto v: adj[u]) {
        if (v == p) continue;
        if (visited[v]) continue;
        d.merge(u, v);
        dfs(v, u, d, k);
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(k);
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        c[i]--;
    }
    adj.resize(n);
    visited.resize(n, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dsu dsu(n);
    int biggest = INT_MIN;
    int biggest_id = -1;
    edges.resize(k);
    ll untouched = n;
    ll sum_edges = 0;
    for (int i = 0; i < k; i++) {
        int u = c[i];
        dfs(u, -1, dsu, i);
        if (dsu.size(u) > biggest) {
            biggest = dsu.size(u);
            biggest_id = i;
        }
        untouched -= dsu.size(u);
        sum_edges += edges[i] / 2;
    }
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        int u = c[i];
        ll sz = dsu.size(u);
        if (biggest_id == i) {
            sz += untouched;
            ans -= (m - sum_edges);
        }

        ans += (sz * (sz - 1)) / 2;
        ans -= edges[i] / 2;
    }
    cout << ans << endl;
    return 0;
}