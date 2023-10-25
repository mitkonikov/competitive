#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

vector<vector<int>> adj;
vector<int> caves;
vector<ll> weight_prefix;
vector<bool> visited;
int NN;

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

LCA* lca = nullptr;

void calc_weight_prefix(int u, int weight) {
    weight_prefix[u] = caves[u] + weight;

    for (int v : adj[u]) {
        if (weight_prefix[v] == -1) {
            calc_weight_prefix(v, weight_prefix[u]);
        }
    }
}

ll find_best(int u) {
    ll best = weight_prefix[u];
    visited[u] = true;

    for (int i = 1; i < NN; i++) {
        if (i == u) continue;

        int v = lca->lca(u, i);
        if (v != 0) continue;
        
        ll cur = weight_prefix[u] + weight_prefix[i] - weight_prefix[v];

        best = max(best, cur);
    }

    for (int v : adj[u]) {
        if (!visited[v]) {
            best = max(best, find_best(v));
        }
    }

    return best;
}

void testCase() {
    cin >> NN;

    adj.clear();
    adj.resize(NN);
    caves.clear();
    caves.resize(NN);
    weight_prefix.clear();
    weight_prefix.resize(NN, -1);
    visited.clear();
    visited.resize(NN, false);

    for (int i = 0; i < NN; i++) {
        cin >> caves[i];
    }

    for (int i = 0; i < NN-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    lca = new LCA(adj);
    calc_weight_prefix(0, 0);

    ll best = find_best(0);
    cout << best << endl;

    delete lca;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        testCase();
    }

    return 0;
}