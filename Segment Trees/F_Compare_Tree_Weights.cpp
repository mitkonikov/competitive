#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<array<int, 2>> edges;
vector<int> timer_in, timer_out;
vector<int> weights;
vector<int> depth;
int counter = 0;

void dfs(int u, int p, int d = 0) {
    depth[u] = d;
    timer_in[u] = counter;
    counter++;
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
    }
    timer_out[u] = counter;
}

struct SegmentTree {
    const static int pw = 1 << 19;
    const static ll def = 0;
    int N = pw;

    struct Node {
        ll value = def;
        Node operator+(const Node &other) {
            return { this->value + other.value };
        }
    };

    vector<Node> seg;
    SegmentTree(int N) { this->N = N; seg.resize(2 * pw); }

    void build(vector<int>& v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind].value = v[l]; return; }
        int m = (l + r) / 2;
        build(v, ind * 2 + 1, l, m);
        build(v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    void put(int i, Node v, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (r - l == 1) { seg[ind].value += v.value; return; }
        int m = (l + r) / 2;
        if (i < m) put(i, v, ind * 2 + 1, l, m);
        else put(i, v, ind * 2 + 2, m, r);
        seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
    }

    Node ask(int i, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (i + 1 >= r) return seg[ind];
        if (i < l) return { };
        int m = (l + r) / 2;
        return ask(i, ind * 2 + 1, l, m) + ask(i, ind * 2 + 2, m, r);
    }
    // result in [b,e) of node that covers [l,r)
    Node askLR(int b, int e, int ind = 0, int l = 0, int r = -1) {
        if (r == -1) r = N;
        if (l>=e || r<=b) return { };
        if (l>=b && r<=e) return seg[ind];
        int m = (l + r) / 2;
        return askLR(b, e, ind * 2 + 1, l, m) + askLR(b, e, ind * 2 + 2, m, r);
    }
};


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    adj.resize(N);
    depth.resize(N);
    edges.resize(N-1);
    weights.resize(N);
    timer_in.resize(N);
    timer_out.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        U--; V--;
        adj[U].push_back(V);
        adj[V].push_back(U);
        edges[i] = { U, V };
    }
    dfs(0, -1);
    int Q;
    cin >> Q;
    SegmentTree tree(N);
    vector<int> tmp(N, 1);
    tree.build(tmp);
    ll sum = N;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int X, W;
            cin >> X >> W;
            tree.put(timer_in[X - 1], { W });
            sum += W;
        } else {
            int Y;
            cin >> Y;
            int U = edges[Y - 1][0];
            int V = edges[Y - 1][1];
            if (depth[V] < depth[U]) {
                swap(U, V);
            }
            // depth[V] > depth[U]
            ll v_sum = tree.askLR(timer_in[V], timer_out[V]).value;
            ll u_sum = sum - v_sum;
            cout << abs(u_sum - v_sum) << endl;
        }
    }
    return 0;
}