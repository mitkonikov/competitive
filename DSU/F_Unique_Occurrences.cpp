#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;

struct edge {
    int u, v, w;
    void read() {
        cin >> u >> v >> w;
        u--; v--; w--;
    }
};

vector<vector<edge>> edges;

struct dsu_save {
    int u, v, parent_u, parent_v;
};

struct dsu {
    vector<int> parent;
    vector<dsu_save> saves;

    dsu(int n) {
        parent.resize(n, -1);
        saves.reserve(n);
    }

    int find_set(int a) {
        if (parent[a] < 0) return a;
        return find_set(parent[a]);
    }

    bool merge(int a, int b, bool save = false) {
        int x = find_set(a), y = find_set(b);
        if (x == y) return false;
        if (-parent[x] < -parent[y]) swap(x, y);
        if (save) saves.push_back({ x, y, parent[x], parent[y] });
        parent[x] += parent[y];
        parent[y] = x;
        return save;
    }

    void rollback() {
        if (saves.empty()) return;
        dsu_save top = saves.back();
        saves.pop_back();
        parent[top.u] = top.parent_u;
        parent[top.v] = top.parent_v;
    }

    bool are_same(int a, int b) {
        return find_set(a) == find_set(b);
    }

    int size(int a) {
        return -parent[find_set(a)];
    }
};

ll ans = 0;
void dfs(int l, int r, dsu &dsu) {
    if (l == r) {
        for (auto &e: edges[l]) {
            ans = ans + (ll)dsu.size(e.u) * dsu.size(e.v);
        }
        return;
    }
    
    int mid = (l + r) / 2;
    int rollback_count = 0;
    for (int i = l; i <= mid; i++) {
        for (auto &e: edges[i]) {
            bool saved = dsu.merge(e.u, e.v, true);
            rollback_count += saved;
        }
    }
    dfs(mid + 1, r, dsu);
    for (int i = 0; i < rollback_count; i++) {
        dsu.rollback();
    }

    rollback_count = 0;
    for (int i = mid + 1; i <= r; i++) {
        for (auto &e: edges[i]) {
            bool saved = dsu.merge(e.u, e.v, true);
            rollback_count += saved;
        }
    }
    dfs(l, mid, dsu);
    for (int i = 0; i < rollback_count; i++) {
        dsu.rollback();
    }
}

int main() {
    cin >> n;
    edges.resize(n + 10);
    dsu dsu(n + 10);
    
    for (int i = 0; i < n - 1; i++) {
        edge e;
        e.read();
        edges[e.w].push_back(e);
    }

    dfs(0, n-1, dsu);
    cout << ans << endl;
    return 0;
}