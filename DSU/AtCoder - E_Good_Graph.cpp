#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

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

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    dsu DSU(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        DSU.merge(u, v);
    }
    int K;
    cin >> K;
    set<pair<int, int>> s;
    for (int i = 0; i < K; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        u = DSU.find_set(u);
        v = DSU.find_set(v);
        s.insert({ min(u, v), max(u, v) });
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        int p1 = DSU.find_set(u);
        int p2 = DSU.find_set(v);
        cout << (s.count({ min(p1, p2), max(p1, p2) }) ? "No" : "Yes") << endl;
    }
    return 0;
}