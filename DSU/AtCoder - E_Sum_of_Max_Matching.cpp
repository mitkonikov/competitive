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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<int, int>>> adj(N);
    struct Edge {
        ll u, v, w;
        bool operator<(const Edge& other) const {
            return w < other.w;
        }
    };
    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
        edges[i] = { u, v, w };
    }
    sort(edges.begin(), edges.end());
    vector<int> A(K), B(K);
    vector<int> bs(N);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
        A[i]--;
        bs[A[i]]--;
    }
    for (int i = 0; i < K; i++) {
        cin >> B[i];
        B[i]--;
        bs[B[i]]++;
    }
    dsu DSU(N);
    ll ans = 0;
    for (int i = 0; i < M; i++) {
        auto [u, v, w] = edges[i];
        if (DSU.are_same(u, v)) continue;
        int ru = DSU.find_set(u);
        int rv = DSU.find_set(v);
        int sum = bs[ru] + bs[rv];
        if ((bs[ru] > 0) ^ (bs[rv] > 0)) {
            ans += (ll)w * abs(min(abs(bs[ru]), abs(bs[rv])));
        }
        DSU.merge(ru, rv);
        bs[ru] = 0;
        bs[rv] = 0;
        int r = DSU.find_set(ru);
        bs[r] = sum;
    }
    cout << ans << endl;
    return 0;
}