#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<int>> adj;

struct LazySegmentTree {
    int N = 0;

    struct Node {
        int value = 0;
        int lazy = 0;
        int size = 1;

        void push(Node& l, Node& r) {
            (l.size == 1 ? l.value : l.lazy) += lazy;
            (r.size == 1 ? r.value : r.lazy) += lazy;
            lazy = 0;
        }

        Node operator+(const Node& other) {
            return {
                this->value + other.value + lazy * size + other.lazy * other.size,
                0,
                size + other.size
            };
        }
    };

    vector<Node> seg;
    LazySegmentTree() {}
    
    void init(int N) {
        this->N = N;
        seg.resize(4 * N);
        build();
    }

    void build(int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { return; }
        int m = (l + r) / 2;
        build(2 * ind + 1, l, m);
        build(2 * ind + 2, m, r);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(int b, int e, int v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (l>=e || r<=b) return;
        if (l>=b && r<=e) {
            seg[ind].lazy += v;
            return;
        }
        int m = (l + r) / 2;
        seg[ind].push(seg[2 * ind + 1], seg[2 * ind + 2]);
        update(b, e, v, 2 * ind + 1, l, m);
        update(b, e, v, 2 * ind + 2, m, r);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 1];
    }

    Node query(int b, int e, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (l>=e || r<=b) return {};
        if (l>=b && r<=e) {
            return seg[ind];
        }
        int m = (l + r) / 2;
        seg[ind].push(seg[2 * ind + 1], seg[2 * ind + 2]);
        return query(b, e, 2 * ind + 1, l, m) + query(b, e, 2 * ind + 2, m, r);
    }
};

template<bool VALS_EDGES>
struct HLD {
    int N, t = 0;
    vector<vector<int>> adj;
    vector<int> parent, sz, depth, rt, timer;
    LazySegmentTree tree;

    HLD(vector<vector<int>> _adj) {
        N = _adj.size();
        adj = _adj;
        parent.resize(N, -1);
        sz.resize(N, 1);
        depth.resize(N, 0);
        rt.resize(N, 0);
        timer.resize(N, 0);
        tree.init(N);
        dfs_sz(0);
        dfs_hld(0);
    }
    int dfs_sz(int u, int p = -1, int d = 0) {
        // erase the parent
        if (p != -1) adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
        parent[u] = p;
        depth[u] = d;
        sz[u] = 1;
        for (auto& v: adj[u]) {
            sz[u] += dfs_sz(v, u, d + 1);
            if (sz[v] > sz[adj[u][0]]) swap(v, adj[u][0]);
        }
        return sz[u];
    }
    void dfs_hld(int u) {
        timer[u] = t++;
        for (auto& v: adj[u]) {
            rt[v] = (v == adj[u][0] ? rt[u] : v);
            dfs_hld(v);
        }
    }
    void process(int u, int v, function<void(int, int)> op) {
        for (; rt[u] != rt[v]; v = parent[rt[v]]) {
            if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
            op(timer[rt[v]], timer[v] + 1);
        }
        if (depth[u] > depth[v]) swap(u, v);
        op(timer[u] + VALS_EDGES, timer[v] + 1);
    }
    void update(int u, int v, int val = 1) {
        process(u, v, [&](int l, int r) {
            tree.update(l, r, val);
        });
    }
    ll query_node(int u) {
        return tree.query(timer[u], timer[u] + 1).value;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    adj.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    HLD<false> hld(adj);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        hld.update(u, v);
    }
    for (int i = 0; i < N; i++) {
        cout << hld.query_node(i) << " ";
    } cout << endl;
    return 0;
}